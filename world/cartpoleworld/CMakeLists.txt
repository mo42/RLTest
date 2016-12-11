set(cartPoleWorldSourceFiles
  CartPoleWorld.cpp
)

set(cartPoleWorldHeaderFiles
  CartPoleAction.h
  CartPoleParameter.h
  CartPoleWeight.h
  CartPoleWorld.h
)

add_library(cartpoleworld ${cartPoleWorldSourceFiles} ${cartPoleWorldHeaderFiles})
