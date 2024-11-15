# Define the compiler and flags
CXX = g++
CXXFLAGS = std=c++17   -Wall -Iinclude

#Define source files and the taeget executable
SOURCES = src/main.cpp src/greet.cpp
TARGET = onlineshoppingmanagement

#Build target
all: $( TARGET)


$( TARGET): $(SOURCES)
     $(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

	 #Clean up build files
	 clean:
	    rm -f $(TARGET)
		