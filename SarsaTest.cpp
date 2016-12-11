#include <iostream>

#include <MazeWorld.h>
#include <Sarsa.h>

using namespace RL;

int main(int argc, char* argv[]) {
  MazeWorld world;
  StateAction stateAction(world.getNumberStates(),
                          std::vector<double>(world.getNumberActions(), 0.0));
  double alpha = 0.1;
  double gamma = 0.9;
  double epsilon = 0.1;
  sarsa(world, stateAction, 100, 100, alpha, gamma, epsilon);
  return 0;
}
