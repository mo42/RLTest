#ifndef SARSA_H_
#define SARSA_H_

#include <iostream>

#include <EpsilonPolicy.h>
#include <IGridWorld.h>
#include <Parameter.h>
#include <RLRandom.h>
#include <RandomPolicy.h>
#include <StateAction.h>

namespace RL {

template <typename TGridState, typename TGridAction>
void sarsa(const IGridWorld<TGridState, TGridAction>& world,
           StateAction& stateAction, Parameter& parameter) {
  while (0 < parameter.walks--) {
    StateAction stateActionOld = stateAction;
    TGridState state;
    world.initialState(state);
    TGridAction action = epsilonPolicy<TGridState, TGridAction>(
        world, stateAction, state, parameter.epsilon);
    double rewards = 0.0;
    for (std::size_t i = 0;
         i < parameter.episodeLength && !world.isTerminal(state); ++i) {
      TGridState nextState;
      double reward = world.act(state, action, nextState);
      TGridAction nextAction = epsilonPolicy<TGridState, TGridAction>(
          world, stateAction, nextState, parameter.epsilon);
      stateAction[state.id][action] =
          stateActionOld[state.id][action] +
          parameter.alpha *
              (reward +
               parameter.gamma * stateActionOld[nextState.id][nextAction] -
               stateActionOld[state.id][action]);
      state = nextState;
      action = nextAction;
      rewards += reward;
    }
    std::cout << rewards << std::endl;
  }
}

} /* namespace RL */

#endif /* SARSA_H_ */
