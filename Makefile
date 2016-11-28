CC = clang++
CFLAGS = -g -std=c++11 -Wall -O0 -c

SarsaTest : SarsaTest.o MazeWorld.o RLRandom.o
	$(CC) SarsaTest.o MazeWorld.o RLRandom.o -o SarsaTest

SarsaTest.o : SarsaTest.cpp Sarsa.h
	$(CC) $(CFLAGS) SarsaTest.cpp

MazeWorld.o : MazeWorld.cpp MazeWorld.h
	$(CC) $(CFLAGS) MazeWorld.cpp

RLRandom.o : RLRandom.cpp RLRandom.h
	$(CC) $(CFLAGS) RLRandom.cpp

.PHONY : clean
clean:
	rm -rf *.o
