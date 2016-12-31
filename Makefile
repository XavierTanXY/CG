CFLAGS=-std=c99 -Wall -Wextra -Werror -pedantic -pedantic-errors -g
LDLIBS=-lglut -lGLU -lGL -lm -lrt


program: main.o shape.o render.o 
	$(CC) -o $@ $^ $(LDLIBS)

main.o: main.c main.h

shape.o: shape.c shape.h

render.o: render.c render.h

clean:
	rm -f program *.o *.aux *.out *.log *.toc

