#ifndef CARTPOLEWORLD_H_
#define CARTPOLEWORLD_H_

#include <Eigen/Dense>
#include <CartPoleAction.h>
#include <CartPoleParameter.h>
#include <CartPoleWeight.h>
#include <IWorld.h>

namespace RL {

class CartPoleWorld : public IWorld<CartPoleParameter, CartPoleAction> {
private:
  const double gravity = 9.8;
  const double cartMass = 1.0;
  const double poleMass = 0.1;
  const double totalMass = cartMass + poleMass;
  const double length = 0.5;
  const double poleMassLength = poleMass * length;
  const double forceMag = 10.0;
  const double timeStep = 0.02;

  const double fourThirds = 1.3333333333333;
  const double twelveDegrees = 0.2094384;

public:
  virtual double act(const CartPoleParameter& state,
                     const CartPoleAction& action,
                     CartPoleParameter& nextState) const;
  virtual bool isTerminal(const CartPoleParameter& state) const;
  virtual void initialState(CartPoleParameter& state) const;
};

} /* namespace RL */

#endif /* CARTPOLEWORLD_H_ */
