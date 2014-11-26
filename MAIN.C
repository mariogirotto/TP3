#include <stdio.h>
#include <string.h> hfgfhgfhf
#include "types.h"

#define FIELD_SIZE 30
#define TAG_SIZE 3
#define OFFSET -128

typedef struct {
	char title[FIELD_SIZE], artist[FIELD_SIZE], album[FIELD_SIZE];
	genre_t genre;
} track_t;

int main (int argc, char *argv[])
{
	FILE *fi;
	char input, aux[128];
	size_t i;
	track_t track;

	if((fi=fopen(argv[1], "rb"))==NULL) return 1;

	fseek(fi, OFFSET, SEEK_END);
/*	fread(aux, TAG_SIZE, 1, fi);
	fread(track.title, FIELD_SIZE, 1, fi);
	fread(track.artist, FIELD_SIZE, 1, fi);
	fread(track.album, FIELD_SIZE, 1, fi);
	fread(aux, FIELD_SIZE+4, 1, fi);
	fread(&track.genre, 1, 1, fi); */

	fread(aux, 128, 1, fi);

	for(i=0; i<127; i++)
		{
			if(aux[i]=='\0') aux[i]='-';
		}

	aux[126]='\0';

	track.title[FIELD_SIZE-1]=track.artist[FIELD_SIZE-1]=track.album[FIELD_SIZE-1]='\0';

	printf("%s%i\n", aux, aux[127]);

	/*printf("%s\n\t%s\n\t\t%s\n%i\n", track.artist, track.title, track.album, track.genre);*/

	fclose(fi);
	return 0;
}
