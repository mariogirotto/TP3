#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "types.h"
#include "mp3_explorer.h"
#include "ADT_vector.h"
#include "ADT_track.h"
#include "ADT_vector_prototypes.h"
#include "ADT_track_prototypes.h"

#define MSG_INVALID_INPUT "Su ingreso no fue válido"

int (*cmp[CMP_FUNCTIONS_QTY])(const void*, const void*)={
	ADT_cmp_title, 
	ADT_cmp_author,
	ADT_cmp_genre};

status_t (*printer[PRINT_FUNCTIONS_QTY])(FILE*, void*)={
	ADT_print_track_as_csv,
	ADT_print_track_as_string};


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
	char aux[MAX_STRING];
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
		aux[0]='\0';
		strcat(aux, config.path);
		strcat(aux, "\\");
		strcat(aux, files[i]);
		if((fi=fopen(aux, "rb"))==NULL) return ERROR_OPENING_FILE;
		if((st=ADT_new_track(fi, &track))!=OK) return st;
		if((st=ADT_vector_append_element(track_vector, track, ADT_destroy_track))!=OK) return st;
		fclose(fi);
	}

	if((st=ADT_sort_vector(track_vector->elements, ADT_vector_get_size(track_vector), sizeof(ADT_track_t*), cmp[config.sort]))!=OK) return st;

	if((st=ADT_print_vector(track_vector, printer[config.fmt], stdout))!=OK) return st;
	if((st=ADT_vector_delete (&track_vector, ADT_destroy_track))!=OK) return st;

	delete_string_array(files,L);

	return 0;
}
