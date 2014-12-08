#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "types.h"
#include "functions.h"

/* ///////////////////// Prototipos ////////////////////////// */
status_t 	get_dir_files (string, size_t *, string**);
status_t	delete_string_array (string [], size_t);
status_t 	validate_arguments (int , char **, config_t*);
/* //////////////////////////////////////////////////////////  */

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
				delete_string_array(*files, used_size);
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

