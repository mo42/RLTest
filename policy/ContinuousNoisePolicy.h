#ifndef CONTINUOUSNOISEPOLICY_H_
#define CONTINUOUSNOISEPOLICY_H_

#include <RLRandom.h>

namespace RL {

template <typename TParameter, typename TAction>
TAction continuousNoisePolicy(const TParameter& theta, const TParameter& state,
                              TParameter& epsilon, double sigma = 0.5) {
  noiseVector<TParameter>(epsilon, sigma);
  TParameter temp = theta + epsilon;
  return temp.transpose() * state;
}

template <typename TParameter, typename TAction>
TAction continuousNoisePolicy(const TParameter& theta, const TParameter& state,
                              double sigma = 0.5) {
  return (theta.transpose() * state) + sigma * normalRandom();
}

} /* namespace RL */

#endif /* CONTINUOUSNOISEPOLICY_H_ */
