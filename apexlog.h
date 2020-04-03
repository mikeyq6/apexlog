#ifndef APEXLOG_H
#define APEXLOG_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h> 
#include "stringbuilder.h"

enum _outputType {
	XML = 1
};

typedef struct _inputFile {
	const char *filename;
	FILE *fp;
} inputFile;

void init();
void convertToXML();

#endif /* APEXLOG_H */