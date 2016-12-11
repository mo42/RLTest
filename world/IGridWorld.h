#ifndef IGRIDWORLD_H_
#define IGRIDWORLD_H_

#include <cstddef>

#include <IWorld.h>

namespace RL {

template <typename TGridState, typename TGridAction>
class IGridWorld : public IWorld<TGridState, TGridAction> {
public:
  virtual std::size_t getNumberStates(void) const = 0;
  virtual std::size_t getNumberActions(void) const = 0;
};

} /* namespace RL */

#endif /* IGRIDWORLD_H_ */
