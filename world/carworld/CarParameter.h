#ifndef CARPARAMETER_H_
#define CARPARAMETER_H_

#include <Eigen/Dense>

/**
 * The state of the car consists of:
 * 1. x position
 * 2. y position
 * 3. x velocity
 * 4. y velocity
 * 5. angle of car in coordinate system
 * 6. angular velocity
 */
typedef Eigen::Matrix<double, 6, 1> CarParameter;

#endif /* CARPARAMETER_H_ */
