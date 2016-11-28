#ifndef SARSA_H_
#define SARSA_H_

#include "EpsilonPolicy.h"
#include "IGridWorld.h"
#include "RLRandom.h"
#include "RandomPolicy.h"
#include "StateAction.h"

namespace RL {

template <typename TGridState, typename TGridAction>
void sarsa(const IGridWorld<TGridState, TGridAction>& world,
           StateAction& stateAction, std::size_t episodeLength,
           std::size_t walks, double alpha, double gamma, double epsilon) {
  while (0 < walks--) {
    StateAction stateActionOld = stateAction;
    TGridState state;
    world.initialState(state);
    TGridAction action = epsilonPolicy<TGridState, TGridAction>(
        world, stateAction, state, epsilon);
    for (std::size_t i = 0; i < episodeLength && !world.isTerminal(state);
         ++i) {
      TGridState nextState;
      double reward = world.act(state, action, nextState);
      TGridAction nextAction = epsilonPolicy<TGridState, TGridAction>(
          world, stateAction, nextState, epsilon);
      stateAction[state.id][action] =
          stateActionOld[state.id][action] +
          alpha * (reward + gamma * stateActionOld[nextState.id][nextAction] -
                   stateActionOld[state.id][action]);
      state = nextState;
      action = nextAction;
    }
  }
}

} /* namespace RL */

#endif /* SARSA_H_ */
