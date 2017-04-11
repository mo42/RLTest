#ifndef CONTINUOUSNOISEPOLICY_H_
#define CONTINUOUSNOISEPOLICY_H_

#include <RLRandom.h>

namespace RL {

/**
 * Return action given parameter vector and state.
 *
 * theta: learned parameter
 * state: current state
 * epsilon: noise vector (parameter space)
 * sigma: random noise (action space)
 *
 * return: action
 */
template <typename TParameter, typename TAction>
TAction continuousNoisePolicy(const TParameter& theta, const TParameter& state,
                              TParameter& epsilon, double sigma = 0.5) {
  noiseVector<TParameter>(epsilon, sigma);
  TParameter temp = theta + epsilon;
  return temp.transpose() * state;
}

/**
 * Return action given parameter vector and state.
 *
 * theta: learned parameter
 * state: current state
 * sigma: random noise
 *
 * return: action
 */
template <typename TParameter, typename TAction>
TAction continuousNoisePolicy(const TParameter& theta, const TParameter& state,
                              double sigma = 0.5) {
  return (theta.transpose() * state) + sigma * normalRandom();
}

} /* namespace RL */

#endif /* CONTINUOUSNOISEPOLICY_H_ */
