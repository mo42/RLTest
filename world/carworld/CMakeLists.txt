set(carWorldSourceFiles
  CarWorld.cpp
)

set(carWorldHeaderFiles
  CarAction.h
  CarParameter.h
  CarWeight.h
  CarWorld.h
)

add_library(carworld ${carWorldSourceFiles} ${carWorldHeaderFiles})
