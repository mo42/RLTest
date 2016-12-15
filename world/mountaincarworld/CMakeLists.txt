set(mountainCarWorldSourceFiles
  MountainCarWorld.cpp
)

set(MountainCarWorldHeaderFiles
  MountainCarParameter.h
  MountainCarWorld.h
)

add_library(mountaincarworld ${mountainCarWorldSourceFiles} ${cartPoleWorldHeaderFiles})
