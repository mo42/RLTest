#include <random>

#include <RLRandom.h>

namespace RL {

std::random_device rd;
std::mt19937 engine(rd());
std::uniform_real_distribution<double> urd(0.0, 1.0);
std::normal_distribution<double> normal(0.0, 1.0);

double normalRandom() { return normal(engine); }

double uniformRandom() { return urd(engine); }

int uniformRandomInteger(int min, int max) {
  return std::uniform_int_distribution<int>(min, max)(engine);
}

} /* namespace RL */
