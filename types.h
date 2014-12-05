#include <stdio.h>
#include <stdlib.h>

typedef char* string;

typedef enum {
	OK,
	ERROR_NULL_POINTER,
	ERROR_MEMORY,
	ERROR_INVALID_ARGUMENT,
	ERROR_NOT_ENOUGH_ARGUMENTS,
	ERROR_INVALID_SORT_TIPE,
	ERROR_INVALID_FORMAT,
	ERROR_OPENING_FILE,
	ERROR_CLOSING_FILE
} status_t;

typedef enum {
	FALSE = 0,
	TRUE = 1
	} bool_t;

typedef enum {
	FMT_CSV,
	FMT_PLAIN_TEXT
	} format_t;

typedef enum {
	SORT_BY_NAME,
	SORT_BY_ARTIST,
	SORT_BY_GENRE
	} sort_t;

typedef struct {
	format_t format;
	sort_t sort;
	string path;
	} config_t;
