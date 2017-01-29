#ifndef RLRANDOM_H_
#define RLRANDOM_H_

namespace RL {

/**
 * Draw a real pseudo-random number from the normal distribution.
 */
double normalRandom(void);

/**
 * Return a real pseudo-random number in the interval [0.0, 1.0].
 */
double uniformRandom(void);

/**
 * Return a pseudo-random integer in the interval [min, max]
 */
int uniformRandomInteger(int min, int max);

/**
 * Fill epsilon with independent normal distributed random numbers
 *
 * epsilon: vector to be filled
 * standardDeviation:
 */
template <typename TParameter>
void noiseVector(TParameter& epsilon, double standardDeviation) {
  for (std::size_t i = 0; i < epsilon.rows(); ++i) {
    epsilon(i) = standardDeviation * normalRandom();
  }
}

} /* namespace RL */

#endif /* RLRANDOM_H_ */
