#include <iostream>

#include <CartPoleWorld.h>
#include <MountainCarWorld.h>
#include <Power.h>

using namespace RL;

void testCartPoleWorld() {
  CartPoleParameter theta;
  CartPoleWorld world;
  Parameter p;
  p.updates = 100;
  p.updatesEpisode = 20;
  p.episodeLength = 5000;
  p.sigma = 0.5;
  power<CartPoleParameter, CartPoleWeight, CartPoleAction>(world, theta, p);
}

void testMountainCarWorld() {
  MountainCarParameter theta;
  MountainCarWorld world;
  Parameter p;
  p.updates = 100;
  p.updatesEpisode = 20;
  p.episodeLength = 5000;
  p.sigma = 0.5;
  power<MountainCarParameter, MountainCarWeight, MountainCarAction>(world,
                                                                    theta, p);
}

int main(int argc, char* argv[]) {
  testCartPoleWorld();
  testMountainCarWorld();
  return 0;
}
