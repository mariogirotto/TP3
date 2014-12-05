#include <stdio.h>
#include <stdlib.h>

typedef char* string;

typedef enum {
	OK,
	ERROR_NULL_POINTER,
	ERROR_MEMORY,
	ERROR_OPENING_FILE,
	ERROR_CLOSING_FILE
} status_t;

