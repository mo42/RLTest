#ifndef POLICYGRADIENT_H_
#define POLICYGRADIENT_H_

#include <Eigen/Dense>

#include <ContinuousNoisePolicy.h>
#include <Parameter.h>
#include <RLRandom.h>

namespace RL {

/**
 * Run an episode.
 *
 * world:
 * theta: parameter of the policy
 * p: parameters
 * return: reward of the episode
 */
template <typename TParameter, typename TAction>
double episode(const IWorld<TParameter, TAction>& world,
               const TParameter& theta, const Parameter& p) {
  double sumRewards = 0.0;
  TParameter state;
  world.initialState(state);
  size_t step = 0;
  do {
    TAction action = continuousNoisePolicy<TParameter, TAction>(theta, state);
    TParameter nextState;
    double reward = world.act(state, action, nextState);
    state = nextState;
    sumRewards += reward;
    ++step;
  } while (step < p.episodeLength && !world.isTerminal(state));
  return sumRewards;
}

template <typename TParameter, typename TAction>
void policyGradientUpdate(const IWorld<TParameter, TAction>& world,
                          TParameter& theta, const Parameter& p) {
  Eigen::MatrixXd dtheta(p.updatesEpisode, theta.rows());
  Eigen::MatrixXd dj(p.updatesEpisode, 1);
  TParameter noise;
  double j = episode(world, theta, p);
  for (size_t i = 0; i < p.updatesEpisode; ++i) {
    noiseVector(noise, 0.2);
    TParameter thetaNoise = theta + noise;
    double deltaj = episode(world, thetaNoise, p) - j;
    dtheta.row(i) = noise;
    dj(i, 0) = deltaj;
  }
  TParameter gradient =
      (dtheta.transpose() * dtheta).inverse() * dtheta.transpose() * dj;
  double n = gradient.norm();
  if (n > 0.0)
    theta += (p.alpha / n) * gradient;
}

template <typename TParameter, typename TAction>
void policyGradient(IWorld<TParameter, TAction>& world, TParameter& theta,
                    const Parameter& p) {
  for (size_t i = 0; i < p.updates; ++i) {
    policyGradientUpdate(world, theta, p);
    double reward = episode(world, theta, p);
    std::cout << i << " " << reward << std::endl;
  }
}

template <typename TParameter>
void resilientBackPropagation(TParameter& theta, TParameter& alpha,
                              TParameter& gradient,
                              TParameter& previousGradient) {
  for (std::size_t i = 0; i < theta.rows(); ++i) {
    if(gradient(i) * previousGradient(i) > 0.0) {
      alpha(i) *= 1.2;
      theta(i) -= alpha(i) * sign(gradient(i));
    } else if(gradient(i) * previousGradient(i) < 0.0) {
      alpha(i) *= 0.5;
      theta(i) += alpha(i) * sign(gradient(i));
    } else {
      theta(i) += alpha(i) * sign(gradient(i));
    }
  }
}

} /* namespace RL */

#endif /* POLICYGRADIENT_H_ */
