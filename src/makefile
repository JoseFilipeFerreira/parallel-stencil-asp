CC=gcc
CFLAGS= -O3 -fopenmp -Wall -Wextra -Wdouble-promotion -Werror=pedantic -Werror=vla -pedantic-errors -Wfatal-errors -flto -march=native -mtune=native

all: stencil2D ASP

stencil2D: stencil2D.c
	$(CC) $(CFLAGS) stencil2D.c -o stencil2D

ASP: asp.c
	$(CC) $(CFLAGS) -ftree-vectorize -fopt-info-vec-all asp.c -o asp

clean:
	rm stencil2D asp
