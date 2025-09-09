# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Directories
INCLUDE_DIR = include
SRC_DIR = src

# MySQL Connector/C++ Paths (USER MUST CONFIGURE THIS)
# Replace with the actual path to your MySQL Connector installation
CONNECTOR_PATH = /usr/local/mysql-connector-c++-8.0

# Flags for linking
LDFLAGS = -L$(CONNECTOR_PATH)/lib64 -lmysqlcppconn8

# Find all .cpp files in the source directory
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
# Generate object file names from source file names
OBJECTS = $(SOURCES:.cpp=.o)

# Target executable name
TARGET = library_app

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -I$(CONNECTOR_PATH)/include/ $^ -o $@ $(LDFLAGS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -I$(CONNECTOR_PATH)/include/ -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
