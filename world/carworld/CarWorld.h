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
public:
  virtual double act(const CarParameter& state, const CarAction& action,
                     CarParameter& nextState) const;
  virtual bool isTerminal(const CarParameter& state) const;
  virtual void initialState(CarParameter& state) const;
};

} /* namespace RL */

#endif /* CARWORLD_H_ */
