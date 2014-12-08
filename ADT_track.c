#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "ADT_track.h"
#include "ADT_track_prototypes.h"

char *genre_dictionary[]={
"Blues",
"Classic Rock",
"Country",
"Dance",
"Disco",
"Funk",
"Grunge",
"Hip-Hop",
"Jazz",
"Metal",
"New Age",
"Oldies",
"Other",
"Pop",
"R&B",
"Rap",
"Reggae",
"Rock",
"Techno",
"Industrial",
"Alternative",
"Ska",
"Death Metal",
"Pranks",
"Soundtrack",
"Euro-Techno",
"Ambient",
"Trip-Hop",
"Vocal",
"Jazz+Funk",
"Fusion",
"Trance",
"Classical",
"Instrumental",
"Acid",
"House",
"Game",
"Sound Clip",
"Gospel",
"Noise",
"Alternative Rock",
"Bass",
"Soul",
"Punk",
"Space",
"Meditative",
"Instrumental Pop",
"Instrumental Rock",
"Ethnic",
"Gothic",
"Darkwave",
"Techno-Industrial",
"Electronic",
"Pop-Folk",
"Eurodance",
"Dream",
"Southern Rock",
"Comedy",
"Cult",
"Gangsta",
"Top 40",
"Christian Rap",
"Pop/Funk",
"Jungle",
"Native US",
"Cabaret",
"New Wave",
"Psychadelic",
"Rave",
"Showtunes",
"Trailer",
"Lo-Fi",
"Tribal",
"Acid Punk",
"Acid Jazz",
"Polka",
"Retro",
"Musical",
"Rock & Roll",
"Hard Rock",
"Folk",
"Folk-Rock",
"National Folk",
"Swing",
"Fast Fusion",
"Bebob",
"Latin",
"Revival",
"Celtic",
"Bluegrass",
"Avantgarde",
"Gothic Rock",
"Progressive Rock",
"Psychedelic Rock",
"Symphonic Rock",
"Slow Rock",
"Big Band",
"Chorus",
"Easy Listening",
"Acoustic",
"Humour",
"Speech",
"Chanson",
"Opera",
"Chamber Music",
"Sonata",
"Symphony",
"Booty Bass",
"Primus",
"Porn Groove",
"Satire",
"Slow Jam",
"Club",
"Tango",
"Samba",
"Folklore",
"Ballad",
"Power Ballad",
"Rhythmic Soul",
"Freestyle",
"Duet",
"Punk Rock",
"Drum Solo",
"Acapella",
"Euro-House",
"Dance Hall",
"Goa",
"Drum & Bass",
"Club House",
"Hardcore",
"Terror",
"Indie",
"BritPop",
"Negerpunk",
"Polsk Punk",
"Beat",
"Christian Gangsta Rap",
"Heavy Metal",
"Black Metal",
"Crossover",
"Contemporary Christian",
"Christian Rock",
"Merengue",
"Salsa",
"Thrash Metal",
"Anime",
"JPop",
"Synthpop",
"Rock/Pop"};

status_t ADT_new_track (FILE* fi, ADT_track_t **track)
{
	char author[AUTHOR_FIELD_SIZE+1], title[TITLE_FIELD_SIZE+1];

	if(fi==NULL || track==NULL) return ERROR_NULL_POINTER;
	if((*track=(ADT_track_t*)malloc(sizeof(ADT_track_t)))==NULL) return ERROR_MEMORY;

	fseek(fi, TITLE_OFFSET, SEEK_END);
	fread(title, TITLE_FIELD_SIZE, 1, fi);
	fread(author, AUTHOR_FIELD_SIZE, 1, fi);
	fseek(fi, GENRE_OFFSET, SEEK_END);
	fread(&((*track)->genre), 1, 1, fi);
	author[AUTHOR_FIELD_SIZE]=title[TITLE_FIELD_SIZE]='\0';
	if(((*track)->author=strdup(author))==NULL) 
	{
		free((*track));
		(*track)=NULL;
		return ERROR_MEMORY;
	}
	if(((*track)->title=strdup(title))==NULL)
	{
		free((*track)->author);
		free((*track));
		(*track)=NULL;
		return ERROR_MEMORY;
	}
	return OK;
}

status_t ADT_destroy_track (void **track)
{
	ADT_track_t **aux;
	if(track==NULL) return ERROR_NULL_POINTER;

	aux=(ADT_track_t**)track;
	free((*aux)->author);
	free((*aux)->title);
	free(*aux);
	*aux=NULL;
	return OK;
}

status_t	ADT_get_author (const ADT_track_t *track, string *author)
{
	if(track==NULL || author==NULL) return ERROR_NULL_POINTER;
	
	*author=track->author;
	return OK;
}

status_t	ADT_get_title (const ADT_track_t *track, string *title)
{
	if(track==NULL || title==NULL) return ERROR_NULL_POINTER;
	
	*title=track->title;
	return OK;
}

status_t	ADT_get_genre (const ADT_track_t *track, genre_t *genre)
{
	if(track==NULL || genre==NULL) return ERROR_NULL_POINTER;

	*genre=track->genre;
	return OK;
}

int		ADT_cmp_author (const void *track1, const void *track2)
/* Esta función no recibe punteros nulos */
{
	return strcmp((*(ADT_track_t**)track1)->author, (*(ADT_track_t**)track2)->author);
}

int		ADT_cmp_title (const void *track1, const void *track2)
/* Esta función no recibe punteros nulos */
{
	return strcmp((*(ADT_track_t**)track1)->title, (*(ADT_track_t**)track2)->title);
}

int		ADT_cmp_genre (const void *track1, const void *track2)
/* Esta función no recibe punteros nulos */
{
	return strcmp(ADT_genre_to_string((*(ADT_track_t**)track1)->genre), ADT_genre_to_string((*(ADT_track_t**)track2)->genre));
}


status_t	ADT_print_track_as_csv (FILE *fo, void *track)
{
	ADT_track_t *aux;

	if(fo==NULL || track==NULL) return ERROR_NULL_POINTER;

	aux=(ADT_track_t*)track;
	fprintf(fo, "%s%c%s%c%s", aux->title, CSV_SEPARATOR, aux->author, CSV_SEPARATOR, ADT_genre_to_string(aux->genre));
	return OK;
}

status_t	ADT_print_track_as_string (FILE *fo, void *track)
{
	if(fo==NULL || track==NULL) return ERROR_NULL_POINTER;

	fprintf(fo, "%s\t%s\t%s", ((ADT_track_t*)track)->title, ((ADT_track_t*)track)->author, ADT_genre_to_string(((ADT_track_t*)track)->genre));
	return OK;
}


string ADT_genre_to_string (genre_t genre)
{
	if(genre <= 148) return genre_dictionary[genre];
	else return MSG_UNKNOWN_GENRE;
}

