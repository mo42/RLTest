#ifndef RLRANDOM_H_
#define RLRANDOM_H_

namespace RL {

/**
 * Return a real pseudo-random number in the interval [0.0, 1.0].
 */
double uniformRandom(void);

/**
 * Return a pseudo-random integer in the interval [min, max]
 */
int uniformRandomInteger(int min, int max);

} /* namespace RL */

#endif /* RLRANDOM_H_ */
