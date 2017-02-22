set(cliffWorldSourceFiles
  CliffWorld.cpp
)

set(cliffWorldHeaderFiles
  CliffAction.h
  CliffState.h
  CliffWorld.h
)

add_library(cliffworld ${cliffWorldSourceFiles} ${cliffWorldHeaderFiles})
