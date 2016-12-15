#include <MountainCarWorld.h>

namespace RL {

double MountainCarWorld::act(const MountainCarState& state,
                             const MountainCarAction& action,
                             MountainCarState& nextState) const {
  nextState(1) = state(1) + 0.001 * (static_cast<double>(action) - 1.0) -
                 0.0025 * cos(3.0 * state(0));
  if (nextState(1) > maxVelocity)
    nextState(1) = maxVelocity;
  else if (nextState(1) < minVelocity)
    nextState(1) = minVelocity;
  nextState(0) = state(0) + nextState(1);
  if (nextState(0) < minPosition) {
    nextState(0) = minPosition;
    nextState(1) = 0.0;
    return -1.0;
  } else if (nextState(0) >= goal) {
    nextState(0) = initialPosition;
    nextState(1) = initialVelocity;
    return 0.0;
  } else {
    return -1.0;
  }
}

bool MountainCarWorld::isTerminal(const MountainCarState& state) const {
  return state(0) >= goal;
}

void MountainCarWorld::initialState(MountainCarState& state) const {
  state(0) = initialPosition;
  state(1) = initialVelocity;
}

} /* namespace RL */
