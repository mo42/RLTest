#include <iostream>

#include <CartPoleWorld.h>
#include <PolicyGradient.h>

using namespace RL;

int main(int argc, char* argv[]) {
  CartPoleParameter theta;
  CartPoleWorld world;
  Parameter p;
  p.updates = 300;
  p.updatesEpisode = 20;
  p.episodeLength = 100;
  p.sigma = 0.5;
  p.alpha = 0.5;
  policyGradient<CartPoleParameter, CartPoleAction>(world, theta, p);
  return 0;
}
