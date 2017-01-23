#include <iostream>

#include <MazeWorld.h>
#include <Parameter.h>
#include <Sarsa.h>

using namespace RL;

int main(int argc, char* argv[]) {
  MazeWorld world;
  StateAction stateAction(world.getNumberStates(),
                          std::vector<double>(world.getNumberActions(), 0.0));
  Parameter parameter;
  parameter.alpha = 0.1;
  parameter.gamma = 0.9;
  parameter.epsilon = 0.1;
  parameter.episodeLength = 1000;
  parameter.walks = 100;
  sarsa(world, stateAction, parameter);
  return 0;
}
