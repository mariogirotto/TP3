#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "types.h"

#define MAX_STRING  200
#define FILES_CHOP  10

#define MSG_INVALID_INPUT "Su ingreso no fue válido"

#define NUMBER_OF_ARGUMENTS 7

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
#define ARG_FORMAT_PLAIN_TEXT "plain"

#define ARG_SORT_BY_NAME "name"
#define ARG_SORT_BY_ARTIST "artist"
#define ARG_SORT_BY_GENRE "genre"

/* ///////////////////// Prototipos ////////////////////////// */
status_t 	get_dir_files (string, size_t *, string**);
status_t	delete_string_array (string [], size_t);
status_t 	validate_arguments (int , char **, config_t*);
/* //////////////////////////////////////////////////////////  */

int main (int argc, char * argv[])
{
	char *dir_name;			/* directorio a explorar */
	size_t  L, i;
	string *files;
	config_t config;
	status_t st;
	FILE *fi;
	ADT_vector_t *track_vector;
	ADT_track_t *track;
	
	if (validate_arguments(argc, argv, &config) != OK)
	{
		fprintf(stderr, "%s\n", MSG_INVALID_INPUT);
		return EXIT_FAILURE;
	}	
    
	if((st=ADT_vector_new(&track_vector))!=OK) return st;
	dir_name=config.path;
	if((st=get_dir_files(dir_name, &L, &files))!=OK) return st;
	for (i=0; i<L; i++)
	{
		if((fi=fopen(files[i], "rb"))==NULL) return ERROR_OPENING_FILE;
		if((st=ADT_new_track(fi, &track))!=OK) return st;
		if((st=ADT_vector_append_element(&track_vector, track, status_t ADT_destroy_track(void**)))!=OK) return st;
	}

	if(config.sort==SORT_BY_NAME)
	{
		qsort(track_vector, ADT_vector_get_size(track_vector), sizeof(ADT_track_t*), int ADT_cmp_title(void*, void*));
	}
	else if(config.sort==SORT_BY_ARTIST)
	{
		qsort(track_vector, ADT_vector_get_size(track_vector), sizeof(ADT_track_t*), int ADT_cmp_author(void*, void*));
	}
	else if(config.sort==SORT_BY_GENRE)
	{
		qsort(track_vector, ADT_vector_get_size(track_vector), sizeof(ADT_track_t*), int ADT_cmp_genre(void*, void*));
	}
	if((st=ADT_print_vector(track_vector, status_t	ADT_print_track_as_string (FILE*, void*), stdout))!=OK) return st;
	if((st=ADT_vector_delete (&track_vector, status_t ADT_destroy_track (void**)))!=OK) return st;
	delete_string_array(files,L);
	return 0;
	


}

status_t get_dir_files (string dir_name, size_t *L, string **files)
{
	DIR  *dfd;
	struct dirent *dp;
	size_t alloc_size;
	size_t used_size = 0;
	string *aux;

	if(dir_name==NULL || L==NULL || files==NULL) return ERROR_NULL_POINTER;

	if ((dfd = opendir(dir_name) ) == NULL) 
	{
		*files=NULL;
		*L = 0;
		return ERROR_OPENING_DIRECTORY;
	}
	if (((*files) = (string *) malloc(sizeof(string) * FILES_CHOP)) == NULL) 
	{
		*files=NULL;
		*L = 0;
		closedir(dfd);
		return ERROR_MEMORY;
	}
	alloc_size = FILES_CHOP;

	while ((dp = readdir(dfd)) != NULL) 
	{
		if (!strcmp(dp->d_name,".") || !strcmp(dp->d_name,"..")) continue;
		if (alloc_size == used_size) 
		{
			if ((aux = (string *) realloc((*files), (alloc_size + FILES_CHOP) * sizeof(string))) == NULL) 
			{
				delete_string_array((*files),used_size);
				*L = 0;
				*files=NULL;
				closedir(dfd);
				return ERROR_MEMORY;
			}
			(*files) = aux;
			alloc_size += FILES_CHOP;
		}
		if(((*files)[used_size++] = strdup(dp->d_name))==NULL)
		{
			delete_string_array((*files),used_size);
			*L = 0;
			*files=NULL;
			closedir(dfd);
			return ERROR_MEMORY;
		}
	}
	closedir(dfd);
	*L = used_size;
	return OK;
}

status_t delete_string_array (string arr[], size_t len)
{
	size_t i;

	if(arr==NULL) return ERROR_NULL_POINTER;

	for (i = 0; i<len; i++)  free(arr[i]);
	free(arr);
	return OK;
}

status_t validate_arguments (int argc, char * argv[], config_t * config)
{

	if (argv == NULL || config==NULL)
		return ERROR_NULL_POINTER;

	if (argc < NUMBER_OF_ARGUMENTS)
		return ERROR_NOT_ENOUGH_ARGUMENTS;
	
	if (strcmp(argv[CMD_FLAG_FORMAT_POSITION], CMD_FLAG_FORMAT) != 0)
		return ERROR_INVALID_ARGUMENT;	
	
	if (strcmp(argv[CMD_ARG_FORMAT_POSITION], ARG_FORMAT_CSV) == 0)
			config->fmt = FMT_CSV;
	else if (strcmp(argv[CMD_ARG_FORMAT_POSITION], ARG_FORMAT_PLAIN_TEXT) == 0)
			config->fmt = FMT_PLAIN_TEXT;
	else return ERROR_INVALID_FORMAT;

	if (strcmp(argv[CMD_FLAG_SORT_POSITION], CMD_FLAG_SORT) != 0)
		return ERROR_INVALID_ARGUMENT;

	if (strcmp(argv[CMD_ARG_SORT_POSITION], ARG_SORT_BY_NAME) == 0)
			config->sort = SORT_BY_NAME;
	else if (strcmp(argv[CMD_ARG_SORT_POSITION], ARG_SORT_BY_ARTIST) == 0)
			config->sort = SORT_BY_ARTIST;
	else if (strcmp(argv[CMD_ARG_SORT_POSITION], ARG_SORT_BY_GENRE) == 0)
			config->sort = SORT_BY_GENRE;
	else return ERROR_INVALID_SORT_TIPE;
		
	if (strcmp(argv[CMD_FLAG_PATH_POSITION], CMD_FLAG_PATH) != 0)
		return ERROR_INVALID_ARGUMENT;

	config->path = argv[CMD_ARG_PATH_POSITION];
	
	return OK;
}

