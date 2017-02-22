#include <CliffWorld.h>
#include <RLRandom.h>

namespace RL {

std::size_t CliffWorld::getNumberStates(void) const { return numberStates; }

std::size_t CliffWorld::getNumberActions(void) const { return numberActions; }

double CliffWorld::act(const CliffState& state, const CliffAction& action,
                       CliffState& nextState) const {
  nextState = state;
  switch (action) {
  case 0:
    if (nextState.x < 11)
      ++nextState.x;
    break;
  case 1:
    if (nextState.y < 3)
      ++nextState.y;
    break;
  case 2:
    if (nextState.x > 0)
      --nextState.x;
    break;
  case 3:
    if (nextState.y > 0)
      --nextState.y;
    break;
  }
  nextState.id = nextState.x + nextState.y * 12;
  if (nextState.x > 0 && nextState.y == 0) {
    nextState.terminal = true;
    if (nextState.x == 11)
      return rewardSuccess;
    else
      return rewardFail;
  } else {
    nextState.terminal = false;
    return rewardRegular;
  }
}

bool CliffWorld::isTerminal(const CliffState& state) const {
  return state.terminal;
}

void CliffWorld::initialState(CliffState& state) const {
  state.x = 0;
  state.y = 0;
  state.id = 0;
  state.terminal = false;
}

const std::size_t CliffWorld::numberStates = 48;
const std::size_t CliffWorld::numberActions = RL::numberCliffActions;

const double CliffWorld::rewardSuccess = -1.0;
const double CliffWorld::rewardFail = -100.0;
const double CliffWorld::rewardRegular = -1.0;

} /* namespace RL */
