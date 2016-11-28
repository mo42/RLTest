#ifndef MAZEWORLD_H_
#define MAZEWORLD_H_

#include <cstddef>

#include "IGridWorld.h"
#include "MazeAction.h"
#include "MazeState.h"

namespace RL {

class MazeWorld : public IGridWorld<MazeState, MazeAction> {
public:
  virtual std::size_t getNumberStates(void) const;
  virtual std::size_t getNumberActions(void) const;
  virtual double act(const MazeState& state, const MazeAction& action,
                     MazeState& nextState) const;
  virtual bool isTerminal(const MazeState& state) const;
  virtual void initialState(MazeState& state) const;

private:
  static const std::size_t numberStates;
  static const std::size_t numberActions;
  static const std::size_t goal;
  static const std::size_t cliff;

  static const double rewardSuccess;
  static const double rewardFail;
  static const double rewardRegular;

  static const double intendedProbability;
};

} /* namespace RL */

#endif /* MAZEWORLD_H_ */
