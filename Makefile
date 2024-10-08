# Simple Makefile

# Compiler and linker flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -w -I./game -I./assets/sprites -I./assets/fonts -I./assets/sound
LDFLAGS = -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Source files and target
SRC = main.cpp game/game.cpp game/global.cpp assets/sprites/sprites.cpp assets/fonts/fonts.cpp assets/sound/sound.cpp 
OBJ = $(SRC:.cpp=.o)
TARGET = ASAtut

# Build target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(TARGET) $(OBJ)

# # Compiler and linker flags
# CXX = g++
# CXXFLAGS = -std=c++17 -Wall -w -I./game
# LDFLAGS = -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# # Directories
# SRCDIR = .
# GAMEDIR = game
# ASSETSDIR = assets

# # Source files and target
# SRC = $(SRCDIR)/main.cpp \
#       $(GAMEDIR)/game.cpp \
#       $(GAMEDIR)/global.cpp \
#       $(ASSETSDIR)/sprites/sprites.cpp \
#       $(ASSETSDIR)/fonts/fonts.cpp \
#       $(ASSETSDIR)/sound/sound.cpp
# OBJ = $(SRC:.cpp=.o)
# TARGET = ASAtut

# # Build target
# all: $(TARGET)

# $(TARGET): $(OBJ)
# 	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

# # Rule to build object files
# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# # Clean up
# clean:
# 	rm -f $(TARGET) $(OBJ)
	