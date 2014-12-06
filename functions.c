#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "types.h"

status_t get_dir_files (string dir_name, size_t *L, string ** files)
{
	DIR  *dfd;
	struct dirent *dp;
	size_t alloc_size;
	size_t used_size = 0;
	string *aux;

	if ((dfd = opendir(dir_name) ) == NULL) 
	{
		*L = 0;
		return ERROR_CANNOT_OPEN_DIRECTORY;
	}
	if ((*files = (string *) malloc(sizeof(string) * FILES_CHOP)) == NULL) 
	{
		*L = 0;
		if(closedir(dfd) == -1) return ERROR_CLOSING_DIRECTORY;
		return ERROR_MEMORY;
	}
	alloc_size = FILES_CHOP;

	while ((dp = readdir(dfd)) != NULL) 
	{
		if (!strcmp(dp->d_name,".") || !strcmp(dp->d_name,"..")) continue;
		if (alloc_size == used_size) 
		{
			if ((aux = (string *) realloc(*files, (alloc_size + FILES_CHOP) * sizeof(string))) == NULL) 
			{
				if((delete_string_array(*files,used_size))!=OK)	
					return ERROR_NULL_POINTER;
				*L = 0;
				if(closedir(dfd) == -1) return ERROR_CLOSING_DIRECTORY;
				return ERROR_MEMORY;
			}
			*files = aux;
			alloc_size += FILES_CHOP;
		}
		if(((*files)[used_size++] = strdup(dp->d_name)) == NULL) return ERROR_MEMORY;

	}
	if(closedir(dfd) == -1) return ERROR_CLOSING_DIRECTORY;
	*L = used_size;
	return OK;
}

status_t delete_string_array (string arr[], size_t len)
{
	size_t i;

	if(arr == NULL) return ERROR_NULL_POINTER;	

	for (i = 0; i<len; i++)  free(arr[i]);
	free(arr);
	
	return OK;
}
