#ifndef MAZESTATE_H_
#define MAZESTATE_H_

namespace RL {

struct MazeState {
  std::size_t id;
  bool terminal;
};

} /* namespace RL */

#endif /* MAZESTATE_H_ */
