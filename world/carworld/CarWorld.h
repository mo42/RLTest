#ifndef CARWORLD_H_
#define CARWORLD_H_

#include <CarAction.h>
#include <CarParameter.h>
#include <CarWeight.h>
#include <Eigen/Dense>
#include <IWorld.h>

namespace RL {

class CarWorld : public IWorld<CarParameter, CarAction> {
private:
  const CarNumber timeStep = 0.01;
  const CarNumber mass = 1.0;
  const CarNumber inertia = 1.0;
  const CarNumber tractionFactor = 1.0;
  const CarNumber resistanceFactor = 10.0;
  const CarNumber dragFactor = 2.0;
  const CarNumber rotationalFactor = 1.0;
public:
  virtual double act(const CarParameter& state, const CarAction& action,
                     CarParameter& nextState) const;
  virtual bool isTerminal(const CarParameter& state) const;
  virtual void initialState(CarParameter& state) const;
};

} /* namespace RL */

#endif /* CARWORLD_H_ */
