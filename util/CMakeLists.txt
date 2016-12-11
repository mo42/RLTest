set(utilSourceFiles
  RLRandom.cpp
)

set(utilHeaderFiles
  RLRandom.h
  StateAction.h
)
  
add_library(util ${utilSourceFiles} ${utilHeaderFiles})
