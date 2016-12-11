#include <iostream>

#include <CartPoleAction.h>
#include <CartPoleParameter.h>
#include <CartPoleWeight.h>
#include <CartPoleWorld.h>
#include <Power.h>

using namespace RL;

int main(int argc, char* argv[]) {
  CartPoleParameter theta;
  CartPoleWorld world;
  power<CartPoleParameter, CartPoleWeight, CartPoleAction>(world, theta, 300,
                                                           20, 5000);
  return 0;
}
