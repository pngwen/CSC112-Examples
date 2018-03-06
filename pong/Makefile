CC=g++
CXXFLAGS=--std=c++11 -g
WIDGET_LIB=widget.o term.o application.o keystream.o
TARGETS=paddleTest

all: $(TARGETS)
paddleTest: $(WIDGET_LIB) paddle.o paddleTest.o
paddle.o: paddle.cpp paddle.h
point.o: point.h point.cpp
widget.o: widget.h widget.cpp
term.o: term.h termmanip.h term.cpp
application.o: application.h application.cpp
keystream.o: keystream.h keystream.cpp
clean: 
	rm -f *.o $(TARGETS)

