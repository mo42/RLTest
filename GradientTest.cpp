#include <iostream>

#include <CartPoleWorld.h>
#include <PolicyGradient.h>

using namespace RL;

int main(int argc, char* argv[]) {
  CartPoleParameter theta = CartPoleParameter::Zero();
  CartPoleWorld world;
  Parameter p;
  p.updates = 100;
  p.updatesEpisode = 20;
  p.episodeLength = 5000;
  p.sigma = 0.5;
  p.alpha = 0.5;
  policyGradient<CartPoleParameter, CartPoleAction>(world, theta, p);
  return 0;
}
