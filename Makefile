# Compiler options
CXX := g++ # You can change this to your preferred compiler
CXXFLAGS := -std=c++11 -Wall

# Source files
SRCS := brainf.h lang.h config.h main.cpp transpile.cpp

# Object files
OBJS := $(filter-out %.h,$(SRCS:.cpp=.o))

# Output binary
TARGET := brainf

# Default installation directory
INSTALL_DIR := /usr/local/bin

# Build rule
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile rule for .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Install rule
install: $(TARGET)
	cp $(TARGET) $(INSTALL_DIR)

local: INSTALL_DIR := $(HOME)/.local/bin
local: $(TARGET)
	cp $(TARGET) $(INSTALL_DIR)
	@echo "Make sure $(INSTALL_DIR) is in your PATH."

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

remove:
	rm -f $(INSTALL_DIR)/$(TARGET)
	rm -f $(HOME)/.local/bin/$(TARGET)

# PHONY targets
.PHONY: all clean install local

# Default target
all: $(TARGET)
