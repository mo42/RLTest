CC = clang++
CFLAGS = -g -std=c++11 -Wall -O0 -c

PowerTest : PowerTest.o CartPoleWorld.o RLRandom.o
	$(CC) PowerTest.o CartPoleWorld.o RLRandom.o -o PowerTest

CartPoleWorld.o : CartPoleWorld.cpp CartPoleWorld.h
	$(CC) $(CFLAGS) -I eigen/ CartPoleWorld.cpp

PowerTest.o : PowerTest.cpp Power.h ContinuousPolicy.h ContinuousNoisePolicy.h
	$(CC) $(CFLAGS) -I eigen/ PowerTest.cpp

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
