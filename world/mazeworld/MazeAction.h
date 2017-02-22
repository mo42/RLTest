#ifndef MAZEACTION_H_
#define MAZEACTION_H_

#include <cstddef>

namespace RL {

/*
 * Movement type in a grid world.
 * 0 is right
 * 1 is up
 * 2 is left
 * 3 is down
 */
typedef std::size_t MazeAction;
const std::size_t numberMazeActions = 4;

} /* namespace RL */

#endif /* MAZEACTION_H_ */

