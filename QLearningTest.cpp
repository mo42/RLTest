#include <iostream>

#include <CliffWorld.h>
#include <Parameter.h>
#include <QLearning.h>

using namespace RL;

void testCliffWorld() {
  CliffWorld world;
  StateAction stateAction(world.getNumberStates(),
                          std::vector<double>(world.getNumberActions(), 0.0));
  Parameter parameter;
  parameter.alpha = 0.1;
  parameter.gamma = 1.0;
  parameter.epsilon = 0.1;
  parameter.episodeLength = 100;
  parameter.episodes = 500;
  qlearning(world, stateAction, parameter);
}

int main(int argc, char* argv[]) {
  testCliffWorld();
  return 0;
}
