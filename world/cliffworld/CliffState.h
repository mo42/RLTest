#ifndef CLIFFSTATE_H_
#define CLIFFSTATE_H_

namespace RL {

struct CliffState {
  std::size_t x;
  std::size_t y;
  std::size_t id;
  bool terminal;
};

} /* namespace RL */

#endif /* CLIFFSTATE_H_ */
