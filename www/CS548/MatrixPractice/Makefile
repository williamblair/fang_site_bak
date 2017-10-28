# Global Makefile for OpenGL progs

# Folder for all of the libraries
EXT_LIBS = C:\TDM-GCC-32\external_libs

# each individual library location
ASSIMP = $(EXT_LIBS)\assimp
GLEW   = $(EXT_LIBS)\glew
GLFW   = $(EXT_LIBS)\glfw
GLM    = $(EXT_LIBS)\glm
STB    = $(EXT_LIBS)\stb

# include directies
INCDIRS = -I$(ASSIMP)\include \
          -I$(GLEW)\include   \
          -I$(GLFW)\include   \
          -I$(GLM)\include    \
          -I$(STB)

# library directies
LIBDIRS = -L$(ASSIMP)\lib \
          -L$(GLEW)\lib   \
          -L$(GLFW)\lib

# link libraries
LIBS = -lopengl32 -lglu32 -lglfw3 -lgdi32 -lassimp -lglew32

# Program specific settings
SOURCES = main.cpp
BIN     = matrixtest.exe
CC      = mingw32-g++
CFLAGS  = -DGLEW_STATIC -std=c++11

all: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(BIN) $(INCDIRS) $(LIBDIRS) $(LIBS)