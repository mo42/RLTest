#ifndef POWER_H_
#define POWER_H_

#include <vector>

#include <ContinuousNoisePolicy.h>
#include <Parameter.h>

namespace RL {

/**
 * Run one episode with length at most episodeLength steps.
 *
 * world: the world in which the algorithm acts
 * theta: parameter of the policy
 * weightRewrds: the weight matrix
 * epsilonRewards
 * p: configuration parameters
 * return: the reward of the episode
 */
template <typename TParameter, typename TAction, typename TWeight>
double episode(const IWorld<TParameter, TAction>& world,
               const TParameter& theta, TWeight& weightRewards,
               TParameter& epsilonRewards, Parameter& p) {
  TParameter state = TParameter::Zero();
  std::vector<double> rewards;
  std::vector<TParameter> epsilons;
  std::vector<TParameter> states;
  std::size_t step = 0;
  do {
    TParameter epsilon;
    double action =
        continuousNoisePolicy<TParameter, TAction>(theta, state, epsilon);
    TParameter nextState;
    double reward = world.act(state, action, nextState);
    rewards.push_back(reward);
    epsilons.push_back(epsilon);
    states.push_back(state);
    state = nextState;
    ++step;
  } while (step < p.episodeLength && !world.isTerminal(state));
  // Sum the rewards such that each entry of rewards is the sum of rewards
  // until the end of the episode (also known as the q function without
  // discount)
  double reward = 0.0;
  for (auto i = rewards.rbegin(); i != rewards.rend(); ++i) {
    reward += *i;
    *i = reward;
  }
  weightRewards = TWeight::Zero();
  epsilonRewards = TParameter::Zero();
  for (std::size_t i = 0; i < rewards.size(); ++i) {
    TWeight weight;
    if (i == 0)
      weight = TWeight::Identity();
    else
      weight = states[i] * states[i].transpose() *
               (1.0 / (states[i].transpose() * p.sigma * states[i]));
    weightRewards += weight * rewards[i];
    epsilonRewards += weight * epsilons[i] * rewards[i];
  }
  return rewards[0];
}

/**
 * Return the update vector of a mean of updatesEpisode many episodes.
 *
 * world: the world in which the algorithm acts
 * theta: parameter of the policy
 * update: the update vector
 * p: configuration parameters
 * return: the mean reward of the episodes
 */
template <typename TParameter, typename TWeight, typename TAction>
double episodes(const IWorld<TParameter, TAction>& world,
                const TParameter& theta, TParameter& update, Parameter p) {
  TWeight sumWeightRewards = TWeight::Zero();
  TParameter sumEpsilonRewards = TParameter::Zero();
  double rewards = 0.0;
  for (size_t i = 0; i < p.updatesEpisode; ++i) {
    TWeight weightRewards;
    TParameter epsilonRewards;
    rewards += episode<TParameter, TAction, TWeight>(
        world, theta, weightRewards, epsilonRewards, p);
    sumWeightRewards += weightRewards;
    sumEpsilonRewards += epsilonRewards;
  }
  sumWeightRewards /= static_cast<double>(p.updatesEpisode);
  sumEpsilonRewards /= static_cast<double>(p.updatesEpisode);
  update = sumWeightRewards.inverse() * sumEpsilonRewards;
  return rewards / static_cast<double>(p.updatesEpisode);
}

template <typename TParameter, typename TWeight, typename TAction>
void power(const IWorld<TParameter, TAction>& world, TParameter& theta,
           Parameter& p) {
  for (size_t i = 0; i < p.updates; ++i) {
    TParameter update;
    episodes<TParameter, TWeight, TAction>(world, theta, update, p);
    theta += update;
  }
}

} /* namespace RL */

#endif /* POWER_H_ */
