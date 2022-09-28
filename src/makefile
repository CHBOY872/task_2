LIBS=-lgtest -lgtest_main -lpthread

ISOSTD=-std=c++11

CPP=g++
CPPFLAGS=-Wall -g

CPPSRCMODULES=$(shell find . -name '*.cpp' | grep -v 'main.cpp')
CPPHEDMODULES=$(CPPSRCMODULES:.cpp=.hpp)
CPPOBJMODULES=$(CPPSRCMODULES:.cpp=.o)

%.o: %.c %.h
	$(CC) $(CFLAGS) $< -c -o $@

%.o: %.cpp %.hpp
	$(CPP) $(CPPFLAGS) $< -c -o $@

ifneq (clean, $(MAKECMDGOALS))
-include deps.mk
endif

deps.mk: $(CPPSRCMODULES)
	$(CC) -MM $^ > $@

main: main.cpp $(CPPOBJMODULES)
	$(CPP) $(CPPFLAGS) $^ -o $@

clean:
	find . -name '*.o' -delete

test: test.cpp $(CPPOBJMODULES)
	$(CPP) $(CPPFLAGS) -g $^ $(LIBS) -o $@ $(ISOSTD)

runtest:
	make test
	make clean

all:
	make main
	make clean