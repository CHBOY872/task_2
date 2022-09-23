CPP=g++
CPPFLAGS=-Wall

ANSI=
ISOSTD=-std=c++11

SRCMODULES=AnyType.cpp Exception.cpp
OBJMODULES=$(SRCMODULES:.cpp=.o)
HPPMODULES=$(SRCMODULES:.cpp=.hpp)

LIBS=-lgtest -lgtest_main -lpthread

%.o: %.cpp %.hpp
	$(CPP) $(CPPFLAGS) $(ANSI) -g $< -c -o $@ $(ISOSTD)

main: main.cpp $(OBJMODULES)
	$(CPP) $(CPPFLAGS) $(ANSI) -g $^ -o $@ $(ISOSTD)

clean:
	rm *.o

ifneq (clean, $(MAKECMDGOALS))
-include deps.mk
endif

test: test.cpp $(OBJMODULES)
	$(CPP) $(CPPFLAGS) $(ANSI) -g $^ $(LIBS) -o $@ $(ISOSTD)

runtest:
	make test
	make clean

all:
	make main
	make clean
