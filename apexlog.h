#ifndef APEXLOG_H
#define APEXLOG_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

enum _outputType {
	XML = 1
};

typedef struct _inputFile {
	const char* filename;
} inputFile;

void init();

#endif /* APEXLOG_H */