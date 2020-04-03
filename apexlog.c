#include "apexlog.h"


int outputType = 0;
inputFile *file;
stringbuilder *sb;

int main(int argc, char** argv) {
	file = (inputFile*)malloc(sizeof(inputFile));
	sb = (stringbuilder*)malloc(sizeof(stringbuilder));
	sb_init(sb);

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
			file->filename = argv[i];
		}
	}

	if(file->filename == NULL) {
		printf("No filename supplied\n");
		printf("Usage: %s [-x] filename\n", argv[0]);
		return 2;
	} else {
		// try to open
		file->fp = fopen(file->filename, "r");
		if(file->fp == NULL) {
			printf("Couldn't open file: %s\n", file->filename);
			return 3;
		}
	}

	switch(outputType) {
		case XML:
			convertToXML();
			break;
		default:
			break;
	}

	fclose(file->fp);
	free(file);
	free(sb);

	return 0;
}

void init() {
	file->filename = NULL;
	file->fp = NULL;
}

void convertToXML() {

}