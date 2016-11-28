#ifndef EPSILONOLICY_H_
#define EPSILONOLICY_H_

#include <limits>

#include "GreedyPolicy.h"
#include "IGridWorld.h"
#include "RLRandom.h"
#include "RandomPolicy.h"
#include "StateAction.h"

namespace RL {

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

} /* namespace RL */

#endif /* EPSILONPOLICY_H_ */
