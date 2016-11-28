#ifndef IWORLD_H_
#define IWORLD_H_

namespace RL {

template <typename TState, typename TAction> class IWorld {
public:
  virtual ~IWorld() = default;

  virtual double act(const TState& state, const TAction& action,
                     TState& nextState) const = 0;
  virtual bool isTerminal(const TState& state) const = 0;
  virtual void initialState(TState& state) const = 0;
};

} /* namespace RL */

#endif /* IWORLD_H_ */
