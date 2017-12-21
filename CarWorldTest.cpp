#include <CarWorld.h>
#include <iostream>

using namespace RL;

int main(int argc, char* argv[]) {
  CarWorld world;
  CarParameter state;
  CarParameter nextState;
  world.initialState(state);
  CarAction action;
  for (int i = 0; i < 256; ++i) {
    world.act(state, action, nextState);
    state = nextState;
    std::cout << state << std::endl;
  }
  return 0;
}
