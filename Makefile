CC=g++
CFLAGS=-c -Wall
LDFLAGS= -lGL -lGLU -lglut
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hello

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

run:
	./$(EXECUTABLE)

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *.swp


