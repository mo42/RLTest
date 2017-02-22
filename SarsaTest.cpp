#include <iostream>

#include <MazeWorld.h>
#include <CliffWorld.h>
#include <Parameter.h>
#include <Sarsa.h>

using namespace RL;

void testMazeWorld() {
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
}

void testCliffWorld() {
  CliffWorld world;
  StateAction stateAction(world.getNumberStates(),
                          std::vector<double>(world.getNumberActions(), 0.0));
  Parameter parameter;
  parameter.alpha = 0.1;
  parameter.gamma = 1.0;
  parameter.epsilon = 0.1;
  parameter.episodeLength = 100;
  parameter.walks = 500;
  sarsa(world, stateAction, parameter);
}

int main(int argc, char* argv[]) {
  testMazeWorld();
  testCliffWorld();
  return 0;
}
