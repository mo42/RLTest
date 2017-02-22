#ifndef CLIFFACTION_H_
#define CLIFFACTION_H_

#include <cstddef>

namespace RL {

/*
 * Movement type in a grid world.
 * 0 is right
 * 1 is up
 * 2 is left
 * 3 is down
 */
typedef std::size_t CliffAction;
const std::size_t numberCliffActions = 4;

} /* namespace RL */

#endif /* CLIFFACTION_H_ */

