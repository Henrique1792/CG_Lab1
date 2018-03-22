SRCS=Ex1/ex1.cpp Ex2/ex2.cpp Ex3/ex3.cpp

all:
	g++ $(SRCS) -o $(SRCS:%.cpp:%) -lGL -lglut -lGLU
