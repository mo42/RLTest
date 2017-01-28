#include <cmath>

#include <CartPoleWorld.h>
#include <RLRandom.h>

namespace RL {

double CartPoleWorld::sign(double a) {
  if (a > 0)
    return 1.0;
  else
    return -1.0;
}

double CartPoleWorld::act(const CartPoleParameter& state,
                          const CartPoleAction& action,
                          CartPoleParameter& nextState) const {
  double x = state(0);
  double xDot = state(1);
  double theta = state(2);
  double thetaDot = state(3);
  double force = (action > 0) ? forceMag : -forceMag;
  double cosTheta = cos(theta);
  double sinTheta = sin(theta);
  double temp =
      (force + poleMassLength * thetaDot * thetaDot * sinTheta) / totalMass;
  double thetaAcc =
      (gravity * sinTheta - cosTheta * temp) /
      (length * (fourThirds - poleMass * cosTheta * cosTheta / totalMass));
  double xAcc = temp - poleMassLength * thetaAcc * cosTheta / totalMass;

  nextState(0) = x + timeStep * xDot + 0.01 * normalRandom();
  nextState(1) = xDot + timeStep * xAcc;
  nextState(2) = theta + timeStep * thetaDot + 0.01 * normalRandom();
  nextState(3) = thetaDot + timeStep * thetaAcc;
  if (std::abs(nextState(0)) > 2.4 || std::abs(nextState(2)) > twelveDegrees)
    return -1.0;
  else
    return 1.0;
}

bool CartPoleWorld::isTerminal(const CartPoleParameter& state) const {
  if (std::abs(state(2)) > twelveDegrees)
    return true;
  else
    return false;
}

void CartPoleWorld::initialState(CartPoleParameter& state) const {
  state = CartPoleParameter::Zero();
}

} /* namespace RL */
