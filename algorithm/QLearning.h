#ifndef QLEARNING_H_
#define QLEARNING_H_

#include <iostream>

#include <EpsilonPolicy.h>
#include <IGridWorld.h>
#include <Parameter.h>
#include <RLRandom.h>
#include <RandomPolicy.h>
#include <StateAction.h>

namespace RL {

template <typename TGridState, typename TGridAction>
void qlearning(const IGridWorld<TGridState, TGridAction>& world,
               StateAction& stateAction, Parameter& parameter) {
  while (0 < parameter.episodes--) {
    StateAction stateActionOld = stateAction;
    TGridState state;
    world.initialState(state);
    double rewards = 0.0;
    for (std::size_t i = 0;
         i < parameter.episodeLength && !world.isTerminal(state); ++i) {
      TGridAction action = epsilonPolicy<TGridState, TGridAction>(
          world, stateAction, state, parameter.epsilon);
      TGridState nextState;
      double reward = world.act(state, action, nextState);
      TGridAction nextAction =
          greedyPolicy<TGridState, TGridAction>(world, stateAction, nextState);
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

#endif /* QLEARNING_H_ */
