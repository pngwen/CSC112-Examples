CC=g++
CXXFLAGS=--std=c++11 -g
LDFLAGS=-lpthread
WIDGET_LIB=widget.o term.o application.o keystream.o timer.o
TARGETS=paddleTest bigNumberTest pong

all: $(TARGETS)
paddleTest: $(WIDGET_LIB) paddle.o paddleTest.o
pong: $(WIDGET_LIB) pong.o main.o ball.o paddle.o bigNumber.o
bigNumberTest: $(WIDGET_LIB) bigNumber.o
bigNumber.o: bigNumber.h bigNumber.cpp
paddle.o: paddle.cpp paddle.h
point.o: point.h point.cpp
widget.o: widget.h widget.cpp
term.o: term.h termmanip.h term.cpp
application.o: application.h application.cpp
keystream.o: keystream.h keystream.cpp
clean: 
	rm -f *.o $(TARGETS)

