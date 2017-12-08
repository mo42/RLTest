#ifndef ADAPTERWORLD_H_
#define ADAPTERWORLD_H_

#include <AdapterAction.h>
#include <AdapterParameter.h>
#include <AdapterWeight.h>
#include <Eigen/Dense>
#include <IGridWorld.h>
#include <IWorld.h>
#include <cmath>

#include <iostream>

namespace RL {

template <typename TGridState, typename TGridAction>
class AdapterWorld : public IWorld<AdapterParameter, AdapterAction> {
private:
  IGridWorld<TGridState, TGridAction>* world;
  std::size_t numberStates;
  std::size_t numberAction;
  TGridState internalState;

  /**
   * Create a one-hot vector that has the one at a specified position.
   *
   * parameter: vector to be set
   * position: position of the one
   */
  void oneHotSet(AdapterParameter& parameter, std::size_t position) const {
    for (int i = 0; i < parameter.rows(); ++i) {
      if (i == static_cast<int>(position)) {
        parameter(i) = 1.0;
      } else {
        parameter(i) = 0.0;
      }
    }
  };

public:
  AdapterWorld(IGridWorld<TGridState, TGridAction>* world) {
    this->world = world;
    numberStates = world->getNumberStates();
    numberAction = world->getNumberActions();
  };
  double act(const AdapterParameter& state, const AdapterAction& action,
             AdapterParameter& nextState) const {
    TGridState internalNextState;
    TGridAction gridAction =
        static_cast<TGridAction>(std::abs(action)) % numberAction;
    double reward = world->act(internalState, gridAction, internalNextState);
    // Dirty trick
    AdapterWorld* p = const_cast<AdapterWorld*>(this);
    p->internalState = internalNextState;
    nextState.resize(numberStates);
    oneHotSet(nextState, internalNextState.id);
    return reward;
  };
  bool isTerminal(const AdapterParameter& state) const {
    return world->isTerminal(internalState);
  };
  void initialState(AdapterParameter& state) const {
    TGridState temporaryState;
    world->initialState(temporaryState);
    // Dirty trick again
    AdapterWorld* p = const_cast<AdapterWorld*>(this);
    p->internalState = temporaryState;
    state.resize(numberStates);
    oneHotSet(state, temporaryState.id);
  };
  int getDim() const { return numberStates; }
};

} /* namespace RL */

#endif /* ADAPTERWORLD_H_ */
