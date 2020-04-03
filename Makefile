CC=gcc
InputFiles=apexlog.c stringbuilder.c

build:
	${CC} -Wall -o apexlog ${InputFiles}

debug:
	${CC} -Wall -o apexlog -D DEBUG=1 ${InputFiles}


clean:
	rm -rvf *.o apexlog