#ifndef CONTINUOUSPOLICY_H_
#define CONTINUOUSPOLICY_H_

namespace RL {

template <typename TParameter, typename TState, typename TAction>
TAction continuousPolicy(const TParameter& theta, const TState& state) {
  return theta.transpose() * state;
}

} /* namespace RL */

#endif /* CONTINUOUSPOLICY_H_ */
