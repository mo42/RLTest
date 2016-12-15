#ifndef MOUNTAINCARWORLD_H_
#define MOUNTAINCARWORLD_H_

#include <Eigen/Dense>
#include <IWorld.h>
#include <MountainCarParameter.h>


namespace RL {

class MountainCarWorld : public IWorld<MountainCarState, MountainCarAction> {
private:
  const MountainCarNumber gravity = 9.8;
  const MountainCarNumber cartMass = 1.0;
  const MountainCarNumber poleMass = 0.1;
  const MountainCarNumber totalMass = cartMass + poleMass;
  const MountainCarNumber length = 0.5;
  const MountainCarNumber poleMassLength = poleMass * length;
  const MountainCarNumber forceMag = 10.0;
  const MountainCarNumber timeStep = 0.02;

  const MountainCarNumber fourThirds = 1.3333333333333;
  const MountainCarNumber twelveDegrees = 0.2094384;

  const MountainCarNumber maxVelocity = 0.07;
  const MountainCarNumber minVelocity = -0.07;

  const MountainCarNumber goal = 0.5;
  const MountainCarNumber minPosition = -1.2;

  const MountainCarNumber initialPosition = -0.52;
  const MountainCarNumber initialVelocity = 0.0;
public:
  virtual double act(const MountainCarState& state,
                     const MountainCarAction& action,
                     MountainCarState& nextState) const;
  virtual bool isTerminal(const MountainCarState& state) const;
  virtual void initialState(MountainCarState& state) const;
};

} /* namespace RL */

#endif /* MOUNTAINCARWORLD_H_ */
