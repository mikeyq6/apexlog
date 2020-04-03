#include "apexlog.h"

int main(int argc, char** argv) {
	init();

	if(argc <= 1) {
		printf("Usage: %s [-x] filename\n", argv[0]);
		return 1;
	}

	for(int i=1; i<argc; i++) {
		if(strncmp(argv[i], "-x", strlen(argv[i])) == 0) {
			printf("Match!\n");
			outputType = XML;
		} else if(strncmp(argv[i], "-o", (int)sizeof(argv[i])) == 0) {
			outputFilename = argv[++i];
		}

		if(i == argc-1) {
			// last argument is input file
			file->filename = argv[i];
		}
	}

	if(outputFilename == NULL) {
		outputFilename = "output";
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

	ofp = fopen(outputFilename, "w");
	if(ofp == NULL) {
		printf("Couldn't open file \"%s\" for writing.\n", outputFilename);
		return 4;
	}

	switch(outputType) {
		case XML:
			convertToXML();
			break;
		default:
			break;
	}

	//printf("Outputting: \"%s\", size: %i, to file: \"%s\"\n", sb->string, sb->size, outputFilename);
	fwrite(sb->string, sizeof(char), sb->size, ofp);

	fclose(file->fp);
	fclose(ofp);
	free(file);
	free(sb);

	return 0;
}

void init() {
	file = (inputFile*)malloc(sizeof(inputFile));
	file->filename = NULL;
	file->fp = NULL;
	sb = (stringbuilder*)malloc(sizeof(stringbuilder));
	outputFilename = NULL;
	outputType = 0;
	sb_init(sb);
}

void convertToXML() {
	sb_append(sb, "<?xml version=\"1.0\"?>\n\0");

}