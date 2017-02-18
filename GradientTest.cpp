#include <iostream>

#include <CartPoleWorld.h>
#include <MountainCarWorld.h>
#include <PolicyGradient.h>

using namespace RL;

void testCartPoleWorld() {
  CartPoleParameter theta = CartPoleParameter::Zero();
  CartPoleWorld world;
  Parameter p;
  p.updates = 100;
  p.updatesEpisode = 20;
  p.episodeLength = 5000;
  p.sigma = 0.5;
  p.alpha = 0.5;
  policyGradient<CartPoleParameter, CartPoleAction>(world, theta, p);
}

void testMountainCarWorld() {
  MountainCarParameter theta = MountainCarParameter::Zero();
  MountainCarWorld world;
  Parameter p;
  p.updates = 100;
  p.updatesEpisode = 20;
  p.episodeLength = 5000;
  p.sigma = 0.5;
  p.alpha = 0.5;
  policyGradient<MountainCarParameter, MountainCarAction>(world, theta, p);
}

int main(int argc, char* argv[]) {
  testCartPoleWorld();
  testMountainCarWorld();
  return 0;
}
