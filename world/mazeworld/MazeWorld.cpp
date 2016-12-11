#include <MazeWorld.h>
#include <RLRandom.h>

namespace RL {

const std::size_t MazeWorld::numberStates = 12;

std::size_t MazeWorld::getNumberStates(void) const { return numberStates; }

std::size_t MazeWorld::getNumberActions(void) const { return numberActions; }

const std::size_t MazeWorld::numberActions = RL::numberActions;

double MazeWorld::act(const MazeState& state, const MazeAction& action,
                      MazeState& nextState) const {
  std::size_t move[numberStates][numberActions] = {
      //{right, up, left, down},
      {1, 0, 0, 3}, // state  0
      {2, 1, 0, 4},
      {2, 2, 1, 5},
      {4, 0, 3, 6},
      {5, 1, 3, 7},
      {5, 2, 4, 8},
      {7, 3, 6, 9},
      {7, 7, 7, 7},
      {8, 5, 7, 11},
      {10, 6, 9, 9},
      {11, 7, 9, 10},
      {11, 11, 11, 11}, // state 11
  };
  nextState.terminal = false;
  if (state.id == 6) {
    MazeAction noisyAction[numberActions][3] = {
        //{intended, perpendicular, perpendicular}
        {0, 1, 3}, // action 0
        {1, 0, 2},
        {2, 1, 3},
        {3, 0, 2} // action 3
    };
    double p = uniformRandom();
    if (p < intendedProbability) {
      // Move to the intended state
      nextState.id = move[state.id][noisyAction[action][0]];
    } else if (p < intendedProbability + (1.0 - intendedProbability) / 2.0) {
      // Move in one of the perpendicular directions
      nextState.id = move[state.id][noisyAction[action][1]];
    } else {
      // Move in one of the perpendicular directions
      nextState.id = move[state.id][noisyAction[action][2]];
    }
  } else {
    nextState.id = move[state.id][action];
  }
  if (nextState.id == cliff) {
    nextState.terminal = true;
    return rewardFail;
  } else if (nextState.id == goal) {
    nextState.terminal = true;
    return rewardSuccess;
  } else {
    return rewardRegular;
  }
}

bool MazeWorld::isTerminal(const MazeState& state) const {
  return state.terminal;
}

void MazeWorld::initialState(MazeState& state) const {
  state.id = 0;
  state.terminal = false;
}

const std::size_t MazeWorld::goal = 11;
const std::size_t MazeWorld::cliff = 7;

const double MazeWorld::rewardSuccess = 10.0;
const double MazeWorld::rewardFail = -10.0;
const double MazeWorld::rewardRegular = -1.0;

const double MazeWorld::intendedProbability = 0.8;

} /* namespace RL */
