CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

TARGET_DIR = target
TARGET = $(TARGET_DIR)/main

SOURCES = src/main.cpp src/parser.cpp 
HEADERS = src/parser.hpp src/command.hpp

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS) | $(TARGET_DIR)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
