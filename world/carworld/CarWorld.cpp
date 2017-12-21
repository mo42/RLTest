#include <cmath>

#include <CarWorld.h>
#include <RLRandom.h>

namespace RL {

CarNumber CarWorld::act(const CarParameter& state, const CarAction& action,
                        CarParameter& nextState) const {
  // Control
  CarNumber throttle = action(0);
  CarNumber steerAngle = action(1);
  // State of the car
  CarNumber x = state(0);
  CarNumber y = state(1);
  CarNumber xDot = state(2);
  CarNumber yDot = state(3);
  CarNumber delta = state(4);
  CarNumber deltaDot = state(5);
  // Calculate the velocity in car coordinates
  CarNumber carXDot = std::cos(delta) * yDot + std::sin(delta) * xDot;
  CarNumber carYDot = -std::sin(delta) * yDot + std::cos(delta) * xDot;
  // Calculate the traction
  CarNumber tractionX = tractionFactor * throttle;
  CarNumber tractionY = 0.0;
  // Calculate the angular acceleration
  CarNumber torque = rotationalFactor * steerAngle;
  CarNumber angularAcceleration = torque / inertia;
  // Calculate the resistance
  CarNumber resistanceX =
      -(resistanceFactor * carXDot + dragFactor * carXDot * std::abs(carXDot));
  CarNumber resistanceY =
      -(resistanceFactor * carYDot + dragFactor * carYDot * std::abs(carYDot));
  CarNumber forceX = tractionX + std::sin(steerAngle) * torque + resistanceX;
  CarNumber forceY = tractionY + std::cos(steerAngle) * torque + resistanceY;
  CarNumber accelerationX = forceX / mass;
  CarNumber accelerationY = forceY / mass;
  CarNumber worldAccelerationX =
      std::cos(delta) * accelerationY + std::sin(delta) * accelerationX;
  CarNumber worldAccelerationY =
      -std::sin(delta) * accelerationY + std::cos(delta) * accelerationX;
  xDot += timeStep * worldAccelerationX;
  yDot += timeStep * worldAccelerationY;
  x += timeStep * xDot;
  y += timeStep * yDot;
  deltaDot += timeStep * angularAcceleration;
  delta += timeStep * deltaDot;
  nextState(0) = x;
  nextState(1) = y;
  nextState(2) = xDot;
  nextState(3) = yDot;
  nextState(4) = delta;
  nextState(5) = deltaDot;
  return 0.0;
}

bool CarWorld::isTerminal(const CarParameter& state) const { return false; }

void CarWorld::initialState(CarParameter& state) const {
  state = CarParameter::Zero();
}

} /* namespace RL */
