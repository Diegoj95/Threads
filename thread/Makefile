CC = g++
CFLAGS = -std=c++11 $(shell pkg-config --cflags opencv4) -lpthread
LIBS = $(shell pkg-config --libs opencv4)

all: thread

thread: thread.cpp
	$(CC) $(CFLAGS) -o thread thread.cpp $(LIBS)

clean:
	rm -f thread
