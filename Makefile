flags=-Wall -O2 -std=c2x
ldflags=

all: binary

binary: binary.o
	cc ${flags} $^ -o $@ ${ldflags}

binary.o: binary.c
	cc ${flags} -c $^

clean:
	rm -f *.o binary