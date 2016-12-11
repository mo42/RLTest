#ifndef GREEDYPOLICY_H_
#define GREEDYPOLICY_H_

#include <limits>

#include <IGridWorld.h>
#include <RLRandom.h>
#include <StateAction.h>

namespace RL {

template <typename TGridState, typename TGridAction>
TGridAction greedyPolicy(const IGridWorld<TGridState, TGridAction>& world,
                         const StateAction& stateAction,
                         const TGridState& state) {
  double max = std::numeric_limits<double>::min();
  TGridAction maxAction = 0;
  for (std::size_t i = 0; i < world.getNumberActions(); ++i) {
    if (max < stateAction[state.id][i]) {
      max = stateAction[state.id][i];
      maxAction = i;
    }
  }
  return maxAction;
}

} /* namespace RL */

#endif /* GREEDYPOLICY_H_ */
