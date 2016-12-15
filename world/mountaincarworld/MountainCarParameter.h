#ifndef MOUNTAINCARPARAMETER_H_
#define MOUNTAINCARPARAMETER_H_

#include <Eigen/Dense>

typedef double MountainCarNumber;

/**
 * The state consists of position and velocity
 */
typedef Eigen::Matrix<MountainCarNumber, 2, 1> MountainCarState;

typedef MountainCarNumber MountainCarAction;

#endif /* MOUNTAINCARPARAMETER_H_ */
