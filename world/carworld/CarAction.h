#ifndef CARACTION_H_
#define CARACTION_H_

#include <CarParameter.h>
#include <Eigen/Dense>

/**
 * The first component denotes the acceleration of the car. The second
 * component denotes the angle of the wheels.
 */
typedef Eigen::Matrix<CarNumber, 2, 1> CarAction;

#endif /* CARACTION_H_ */
