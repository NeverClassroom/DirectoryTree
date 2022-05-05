CC=g++
CFLAGS=-c -Wall -I.
LDFLAGS=
SOURCES=main.cpp
EXECUTABLE=main

OBJECTS=$(SOURCES:.cpp=.o)

FLAGS   = -Iinclude

all: $(SOURCES) $(EXECUTABLE)
