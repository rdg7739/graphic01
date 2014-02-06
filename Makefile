#!smake
#  @@ Makefile for CMSC 435/634 - Project 1: Simple scene
#  @@ Jian Chen (jichen@umbc.edu)
#

MACHINE= $(shell uname -s)


ifeq ($(MACHINE),Darwin)
	OPENGL_INC= -FOpenGL
	OPENGL_LIB= -framework OpenGL -framework GLUT -framework Cocoa
else
	OPENGL_INC= -I/usr/include
	OPENGL_LIB= -L/usr/lib64 
	LLDLIBS = -lglut -lGL -lGLU -lGL -lXmu -lXext -lX11 -lm
endif

CXX=g++
COMPILER_FLAGS= -g

INCLUDE= $(OPENGL_INC)
LIBS= $(OPENGL_LIB) $(LLDLIBS) 

TARGETS = MyCoolModel

SRCS = MyCoolModel.c 01primitives.c  01primitivesUtil.c trackball.c model.c

default : $(TARGETS)

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CXX) -c $(COMPILER_FLAGS) -o $@ $< $(INCLUDE)

MyCoolModel: MyCoolModel.o 01primitives.o  01primitivesUtil.o trackball.o model.o
	$(CXX) $(COMPILER_FLAGS) $(LIBS) MyCoolModel.o 01primitives.o 01primitivesUtil.o trackball.o  model.o -o MyCoolModel

clean:
	rm -f $(OBJS) $(TARGETS) *~
