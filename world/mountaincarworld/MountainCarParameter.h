#ifndef MOUNTAINCARPARAMETER_H_
#define MOUNTAINCARPARAMETER_H_

#include <Eigen/Dense>

typedef double MountainCarNumber;

/**
 * The state consists of position and velocity
 */
typedef Eigen::Matrix<MountainCarNumber, 2, 1> MountainCarParameter;

typedef MountainCarNumber MountainCarAction;

typedef Eigen::Matrix<MountainCarNumber, 2, 2> MountainCarWeight;

#endif /* MOUNTAINCARPARAMETER_H_ */
