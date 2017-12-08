#include <cmath>

#include <CarWorld.h>
#include <RLRandom.h>

namespace RL {

double CarWorld::act(const CarParameter& state, const CarAction& action,
                     CarParameter& nextState) const {}

bool CarWorld::isTerminal(const CarParameter& state) const { return false; }

void CarWorld::initialState(CarParameter& state) const {
  state = CarParameter::Zero();
}

} /* namespace RL */
