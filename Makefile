CPP = g++
SRC1 = ./Ex1/src/*.cpp
SRC2 = ./Ex2/src/*.cpp
SRC3 = ./Ex3/src/*.cpp
SRCS = $(SRC1) $(SRC2) $(SRC3)
OUTPUT1 = ./Ex1/ex1
OUTPUT2 = ./Ex2/ex2
OUTPUT3 = ./Ex3/ex3
EXE= ./Ex1/ex1 ./Ex2/ex2 ./Ex3/ex3
LIBS = -lGL -lglut -lGLU
.PHONY: all Ex1 Ex2 Ex3

all: Ex1 Ex2 Ex3
	echo Done

Ex1:
	@$(CPP) $(SRC1) -o $(OUTPUT1) $(LIBS)
Ex2:
	@$(CPP) $(SRC2) -o $(OUTPUT2) $(LIBS)
Ex3:
	@$(CPP) $(SRC3) -o $(OUTPUT3) $(LIBS)

run1:
	$(OUTPUT1)

run2:
	$(OUTPUT2)

run3:
	$(OUTPUT3)
clean:
	rm -rf $(SRCS:.cpp=.o) $(EXE)
