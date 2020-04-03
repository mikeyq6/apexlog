#include "stringbuilder.h"

void sb_init(stringbuilder *sb) {
	sb->string = NULL;
	sb->size = 0;
	sb->bufferSize = BUFFER_INCREMENT;

#ifdef DEBUG
	runTests();
#endif

}
void sb_append(stringbuilder *sb, const char* str) {
	int len = strlen(str);

	if(sb->string == NULL) {
		//printf("str: %s\n", str);
		while(len > sb->bufferSize) {
			// Increase buffer size
			sb->bufferSize += BUFFER_INCREMENT;
		}
		sb->string = (char *)malloc(sizeof(char) * sb->bufferSize + 1);
		strcpy(sb->string, str);
		sb->size = len;
		sb->string[sb->size] = '\0';
	} else {
		size_t newSize = len + (size_t)sb->size;

		if(newSize > sb->bufferSize) {
			// printf("Buffer increased from %i", sb->bufferSize);
			while(newSize > sb->bufferSize) {
				// Increase buffer size
				sb->bufferSize += BUFFER_INCREMENT;
			}
			// printf(" to %i\n", sb->bufferSize);

			char* temp = (char*)malloc(sizeof(char) * sb->size);
			strcpy(temp, sb->string);
			sb->string = (char *)realloc(sb->string, sb->bufferSize + 1);

			// copy the string back into the struct
			strcpy(sb->string, temp);
			
			free(temp);
		}
		// Append the given string
		for(int i=0; i<len; i++) {
			sb->string[sb->size + i] = str[i];
		}
		sb->size += len;
		sb->string[sb->size] = '\0';

	}
}

#ifdef DEBUG
void runTests() {
	// Arrange
	stringbuilder *sb = (stringbuilder*)malloc(sizeof(stringbuilder));
	sb->string = NULL;
	sb->size = 0;
	sb->bufferSize = BUFFER_INCREMENT;

	const char* s1 = "Initial String";
	const char* s2 = ", plus this one!";
	const char* s3 = "This!";
	const char* s4 = " This should really overload the buffer: Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?";
	char buffer[5000];
	strcpy(buffer, s1);
	strcat(buffer, s2);
	//printf("buffer=%s\n", buffer);

	// Act

	sb_append(sb, s1);
	//printf("sb->string: %s\n", sb->string);
	assert(strcmp(sb->string, s1) == 0);
	assert(sb->size == 14);

	sb_append(sb, s2);
	// printf("sb->string: %s\n", sb->string);
	assert(strcmp(sb->string, buffer) == 0);
	assert(sb->size == 30);

	strcat(buffer, s3);
	sb_append(sb, s3);
	// printf("sb->string: %s\n", sb->string);
	assert(strcmp(sb->string, buffer) == 0);
	assert(sb->size == 35);

	strcat(buffer, s4);
	sb_append(sb, s4);
	// printf("sb->string: %s\n", sb->string);
	assert(strcmp(sb->string, buffer) == 0);

	free(sb);
}
#endif