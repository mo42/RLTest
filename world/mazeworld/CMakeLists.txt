set(mazeWorldSourceFiles
  MazeWorld.cpp
)

set(mazeWorldHeaderFiles
  MazeAction.h
  MazeState.h
  MazeWorld.h
)

add_library(mazeworld ${mazeWorldSourceFiles} ${mazeWorldHeaderFiles})
