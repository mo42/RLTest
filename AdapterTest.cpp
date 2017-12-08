#include <AdapterWorld.h>
#include <MazeWorld.h>
#include <CliffWorld.h>
#include <Power.h>
#include <PolicyGradient.h>
#include <iostream>

using namespace RL;

void testMazeWorld() {
  MazeWorld world;
  AdapterWorld<MazeState, MazeAction> adapterWorld(&world);
  AdapterParameter theta;
  theta.resize(adapterWorld.getDim());
  Parameter p;
  p.updates = 1000;
  p.updatesEpisode = 20;
  p.episodeLength = 5000;
  p.sigma = 8.0;
  p.alpha = 0.9;
  policyGradient<AdapterParameter, AdapterAction>(adapterWorld, theta, p);
}

void testCliffWorld() {
  CliffWorld world;
  AdapterWorld<CliffState, CliffAction> adapterWorld(&world);
  AdapterParameter theta;
  theta.resize(adapterWorld.getDim());
  Parameter p;
  p.updates = 1000;
  p.updatesEpisode = 20;
  p.episodeLength = 5000;
  p.sigma = 0.5;
  p.alpha = 0.9;
  policyGradient<AdapterParameter, AdapterAction>(adapterWorld, theta, p);
}

int main(int argc, char* argv[]) {
  //testCliffWorld();
  testMazeWorld();
  return 0;
}
