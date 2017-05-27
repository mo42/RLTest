#ifndef GREEDYPOLICY_H_
#define GREEDYPOLICY_H_

#include <limits>

#include <IGridWorld.h>
#include <RLRandom.h>
#include <StateAction.h>
#include <Value.h>

namespace RL {

/**
 * Return greedy action.
 *
 * world:
 * stateAction: the stateAction function
 * state: current state
 *
 * return: action
 */
template <typename TGridState, typename TGridAction>
TGridAction greedyPolicy(const IGridWorld<TGridState, TGridAction>& world,
                         const StateAction& stateAction,
                         const TGridState& state) {
  double max = std::numeric_limits<double>::lowest();
  TGridAction maxAction = 0;
  for (std::size_t i = 0; i < world.getNumberActions(); ++i) {
    if (max < stateAction[state.id][i]) {
      max = stateAction[state.id][i];
      maxAction = i;
    }
  }
  return maxAction;
}

/**
 * Return greedy action.
 *
 * world:
 * value: the value function
 * state: current state
 *
 * return: action
 */
template <typename TGridState, typename TGridAction>
TGridAction greedyPolicy(const IGridWorld<TGridState, TGridAction>& world,
                         const Value& value,
                         const TGridState& state) {
  double max = std::numeric_limits<double>::lowest();
  TGridAction maxAction = 0;
  for (std::size_t i = 0; i < world.getNumberActions(); ++i) {
    TGridState nextState;
    world.act(state, i, nextState);
    if(max < value[nextState.id]) {
      max = value[nextState.id];
      maxAction = i;
    }
  }
  return maxAction;
}

} /* namespace RL */

#endif /* GREEDYPOLICY_H_ */
