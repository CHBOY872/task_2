CPP=g++
CPPFLAGS=-Wall

ANSI=-ansi
ISOSTD=-std=c++98

SRCMODULES=AnyType.cpp
OBJMODULES=$(SRCMODULES:.cpp=.o)
HPPMODULES=$(SRCMODULES:.cpp=.hpp)

%.o: %.cpp %.hpp
	$(CPP) $(CPPFLAGS) $(ANSI) -g $< -c -o $@ $(ISOSTD)

main: main.cpp $(OBJMODULES)
	$(CPP) $(CPPFLAGS) $(ANSI) -g $^ -o $@ $(ISOSTD)