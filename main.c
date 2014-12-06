#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MSG_INVALID_INPUT "Su ingreso no fue válido"

#define CMD_FLAG_FORMAT_POSITION 1
#define CMD_ARG_FORMAT_POSITION 2
#define CMD_FLAG_SORT_POSITION 3
#define CMD_ARG_SORT_POSITION 4
#define CMD_FLAG_PATH_POSITION 5
#define CMD_ARG_PATH_POSITION 6

#define CMD_FLAG_FORMAT "-fmt"
#define CMD_FLAG_SORT "-sort"
#define CMD_FLAG_PATH "-path"

#define ARG_FORMAT_CSV "csv"
#define ARG_FORMAT_PLAIN_TEXT "PLAIN"

#define ARG_SORT_BY_NAME "name"
#define ARG_SORT_BY_ARTIST "artist"
#define ARG_SORT_BY_GENRE "genre"

int main (int argc, char * argv[])
{
	config_t config;
	
	if ((validate_arguments(argc, argv, &config) != OK)
	{
		fprintf(stderr, "%s\n" MSG_INVALID_INPUT)
		return EXIT_FAILURE;
	}

	


status_t validate_arguments (int argc, char * argv[], config_t * config)
{

	if (argv == NULL)
		return ERROR_NULL_POINTER;

	if (argc < NUMBER_OF_ARGUMENTS)
		return ERROR_NOT_ENOUGH_ARGUMENTS;
	
	if(strcmp(argv[CMD_FLAG_FORMAT_POSITION], CMD_FLAG_FORMAT) != 0)
		return ERROR_INVALID_ARGUMENT;
	
	
	if	(strcmp(argv[CMD_ARG_FORMAT_POSITION], ARG_FORMAT_CSV) == 0)
			config->fmt = FMT_CSV;
	else if (strcmp(argv[CMD_ARG_FORMAT_POSITION], ARG_FORMAT_PLAIN_TEXT) == 0)
			config->fmt = FMT_PLAIN_TEXT;
	else	return ERROR_INVALID_FORMAT;

	if(strcmp(argv[CMD_FLAG_SORT_POSITION], CMD_FLAG_SORT) != 0)
		return ERROR_INVALID_ARGUMENT;

	if	(strcmp(argv[CMD_ARG_SORT_POSITION], ARG_SORT_BT_NAME) == 0)
			config->sort = SORT_BT_NAME;
	else if (strcmp(argv[CMD_ARG_SORT_POSITION], ARG_SORT_BY_ARTIST) == 0)
			config->sort = SORT_BY_ARTIST;
	else if (strcmp(argv[CMD_ARG_SORT_POSITION], ARG_SORT_BY_GENRE) == 0)
			config->sort = SORT_BY_GENRE;
	else	return ERROR_INVALID_SORT_TIPE;
		
	if(strcmp(argv[CMD_FLAG_PATH_POSITION], CMD_FLAG_PATH) != 0)
		return ERROR_INVALID_ARGUMENT;

	config->path = argv[CMD_ARG_PATH_POSITION];
	
	return OK
}
