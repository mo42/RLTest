#ifndef RANDOMPOLICY_H_
#define RANDOMPOLICY_H_

#include "IGridWorld.h"

namespace RL {

template <typename TGridState, typename TGridAction>
TGridAction randomPolicy(const IGridWorld<TGridState, TGridAction>& world) {
  return static_cast<TGridAction>(
      uniformRandomInteger(0, world.getNumberActions()));
}

} /* namespace RL */

#endif /* RANDOMPOLICY_H_ */
