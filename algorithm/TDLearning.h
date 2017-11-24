#ifndef TDLEARNING_H_
#define TDLEARNING_H_

#include <iostream>

#include <EpsilonPolicy.h>
#include <IGridWorld.h>
#include <Parameter.h>
#include <Types.h>
#include <Value.h>

namespace RL {

template <typename TGridState, typename TGridAction>
void tdlearning(const IGridWorld<TGridState, TGridAction>& world, Value& value,
                Parameter& parameter) {
  while (parameter.walks-- > 0) {
    TRLValue rewards = 0.0;
    Value valueOld = value;
    TGridState state;
    world.initialState(state);
    for (std::size_t i = 0; i < parameter.episodeLength; ++i) {
      TGridAction action = epsilonPolicy<TGridState, TGridAction>(world, value,
        state, parameter.epsilon);
      TGridState nextState;
      TRLValue reward = world.act(state, action, nextState);
      rewards += reward;
      value[state.id] = valueOld[state.id] + parameter.alpha
        * (reward + parameter.gamma * valueOld[nextState.id] - valueOld[state.id]);
      state = nextState;
      if(world.isTerminal(state)) {
        value[state.id] = reward;
        break;
      }
    }
    std::cout << rewards << std::endl;
  }
}

} /* namespace RL */

#endif /* TDLEARNING_H_ */
