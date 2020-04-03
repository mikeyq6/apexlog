CC=gcc

build:
	${CC} -Wall -o apexlog apexlog.c

clean:
	rm -rvf *.o apexlog