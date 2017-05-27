#ifndef EPSILONOLICY_H_
#define EPSILONOLICY_H_

#include <limits>

#include <GreedyPolicy.h>
#include <IGridWorld.h>
#include <RLRandom.h>
#include <RandomPolicy.h>
#include <StateAction.h>
#include <Value.h>

namespace RL {

/**
 * Return epsilon greedy action.
 *
 * world:
 * stateAction: the stateAction function
 * state: current state
 * epsilon: probability of selecting the greedy policy
 *
 * return: action
 */
template <typename TGridState, typename TGridAction>
TGridAction epsilonPolicy(const IGridWorld<TGridState, TGridAction>& world,
                          const StateAction& stateAction,
                          const TGridState& state, double epsilon) {
  if (uniformRandom() > epsilon) {
    return greedyPolicy<TGridState, TGridAction>(world, stateAction, state);
  } else {
    return randomPolicy<TGridState, TGridAction>(world);
  }
}

/**
 * Return epsilon greedy action.
 *
 * world:
 * value: the value function
 * state: current state
 * epsilon: probability of selecting the greedy policy
 *
 * return: action
 */
template <typename TGridState, typename TGridAction>
TGridAction epsilonPolicy(const IGridWorld<TGridState, TGridAction>& world,
                          const Value& value,
                          const TGridState& state, double epsilon) {
  if (uniformRandom() > epsilon) {
    return greedyPolicy<TGridState, TGridAction>(world, value, state);
  } else {
    return randomPolicy<TGridState, TGridAction>(world);
  }
}

} /* namespace RL */

#endif /* EPSILONPOLICY_H_ */
