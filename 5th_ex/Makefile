TARGET = a.out
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -fsanitize=address -std=c++20

SRC = $(wildcard *.cpp)

all: build run

build:
	$(CXX) $(CXXFLAGS) $(SRC)

run: build
	./$(TARGET)

clean:
	rm -f $(TARGET)