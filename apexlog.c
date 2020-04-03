#include "apexlog.h"


int outputType = 0;
inputFile file;

int main(int argc, char** argv) {

	if(argc <= 1) {
		printf("Usage: %s [-x] filename\n", argv[0]);
		return 1;
	}

	for(int i=1; i<argc; i++) {
		if(strncmp(argv[i], "-x", (int)sizeof(argv[i]))) {
			outputType = XML;
		}

		if(i == argc-1) {
			// last argument is input file
			file.filename = argv[i];
		}
	}

	if(file.filename == NULL) {
		printf("No filename supplied\n";)
		printf("Usage: %s [-x] filename\n", argv[0]);
		return 2;
	}

	

	return 0;
}

void init() {
	file.filename = NULL;
}