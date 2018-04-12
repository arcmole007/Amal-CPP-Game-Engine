# We using makefile to compile our game engine
# Credits to lazyfoo's production
# April 4 2018
# Nur Akmal Bin Jalil


# Object we used in the game
MAIN_OBJECT = main.cpp

# All the Object that we used for the engine
GAME_OBJECT = Game.cpp

# Compiler that we used for our game
COMPILER = g++

# Standard c++ that we use
# There is a reason I used this but I can't remember what
# That kids where you comments everything
STANDARD = -std=c++11

# The path where we find the include for SDL
# Specifie the folder
INCLUDE_PATHS = -IC:\minGW_SDL2_lib\include\SDL2

# The path where we find all the additional library we'll need
LIBRARY_PATHS = -LC:\minGW_SDL2_lib\lib

# COMPILER_FLAGS specifies the additional compilation options we're using
COMPILER_FLAGS = -w -Wl,-subsystem,windows

# LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

# OBJ_NAME specifies the name of our exectuable
EXE_OBJECT = main

# This is the target that compilers our executable
all : $(MAIN_OBJECT)
	$(COMPILER) $(STANDARD) $(MAIN_OBJECT) $(GAME_OBJECT) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS) -o $(EXE_OBJECT)