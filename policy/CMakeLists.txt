set(policyHeaderFiles
  ContinuousNoisePolicy.h
  ContinuousPolicy.h
  EpsilonPolicy.h
  GreedyPolicy.h
  RandomPolicy.h
)
  
add_library(policy ${policyHeaderFiles})
