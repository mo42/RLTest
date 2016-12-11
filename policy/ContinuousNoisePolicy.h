#ifndef CONTINUOUSNOISEPOLICY_H_
#define CONTINUOUSNOISEPOLICY_H_

#include <RLRandom.h>

namespace RL {

template <typename TParameter>
void noiseVector(TParameter& epsilon, double standardDeviation) {
  for (std::size_t i = 0; i < epsilon.rows(); ++i) {
    epsilon(i) = standardDeviation * uniformRandom();
  }
}

template <typename TParameter, typename TAction>
TAction continuousNoisePolicy(const TParameter& theta, const TParameter& state,
                              TParameter& epsilon, double sigma = 0.5) {
  noiseVector<TParameter>(epsilon, sigma);
  TParameter temp = theta + epsilon;
  return temp.transpose() * state;
}

} /* namespace RL */

#endif /* CONTINUOUSNOISEPOLICY_H_ */
