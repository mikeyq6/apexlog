#ifndef STRINGBUILDER_H
#define STRINGBUILDER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define DEBUG 1
#define BUFFER_INCREMENT 10

typedef struct _stringbuilder {
	char* string;
	int size;
	int bufferSize;
} stringbuilder;

void sb_init(stringbuilder *sb);
void sb_append(stringbuilder *sb, const char* str);

#ifdef DEBUG
void runTests();
#endif

#endif /* STRINGBUILDER_H */