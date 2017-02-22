#ifndef CLIFFWORLD_H_
#define CLIFFWORLD_H_

#include <cstddef>

#include <IGridWorld.h>
#include <CliffAction.h>
#include <CliffState.h>

namespace RL {

class CliffWorld : public IGridWorld<CliffState, CliffAction> {
public:
  virtual std::size_t getNumberStates(void) const;
  virtual std::size_t getNumberActions(void) const;
  virtual double act(const CliffState& state, const CliffAction& action,
                     CliffState& nextState) const;
  virtual bool isTerminal(const CliffState& state) const;
  virtual void initialState(CliffState& state) const;

private:
  static const std::size_t numberStates;
  static const std::size_t numberActions;

  static const double rewardSuccess;
  static const double rewardFail;
  static const double rewardRegular;
};

} /* namespace RL */

#endif /* CLIFFWORLD_H_ */
