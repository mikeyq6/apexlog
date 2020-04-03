CC=gcc
InputFiles=apexlog.c stringbuilder.c

build:
	${CC} -Wall -o apexlog ${InputFiles}

clean:
	rm -rvf *.o apexlog