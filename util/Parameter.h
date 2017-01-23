#ifndef PARAMETER_H_
#define PARAMETER_H_

namespace RL {

class Parameter {
public:
  /**
   * Number of total updates of the value function.
   */
  std::size_t updates;

  /**
   * Number of updates per episode.
   */
  std::size_t updatesEpisode;
  std::size_t walks;
  std::size_t episodeLength;

  double alpha;
  double beta;

  /**
   * This is usually the discounting factor.
   */
  double gamma;

  double sigma;

  double epsilon;
};

} /* namespace RL */

#endif /* PARAMETER_H_ */
