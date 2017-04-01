objects = main.o glslprogram.o scene.o
CFLAGS = $(DEBUG) -Wall -c
INCLUDEDIR = /usr/local/include/
LIBDIR = /usr/local/lib

gas2d : $(objects)
	clang++ -stdlib=libc++ -O0 -g -o gas2d $(objects) -L$(LIBDIR) -lglfw -lGLEW -framework OpenGL
main.o : main.cpp glinclude.h scene.h
	clang++ -g -c main.cpp -I$(INCLUDEDIR)
glslprogram.o : glslprogram.cpp glinclude.h
	clang++ -g -c glslprogram.cpp -I$(INCLUDEDIR)
scene.o : scene.cpp glinclude.h glslprogram.h
	clang++ -g -c scene.cpp -I$(INCLUDEDIR)

.PHONY : clean
clean:
	-rm gas2d $(objects)
