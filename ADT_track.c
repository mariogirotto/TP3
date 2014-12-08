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
<<<<<<< HEAD:ADT_track.C
	if(genre <= 148) return genre_dictionary[genre];
	else return MSG_UNKNOWN_GENRE;
=======
	/* Los nombres de los géneros responden a la tabla extendida de winamp de 148 géneros. */
	switch(genre)
	{
	case 0: return "Blues";
		break;

	case 1: return "Classic Rock";
		break;

	case 2: return "Country";
		break;

	case 3: return "Dance";
		break;

	case 4: return "Disco";
		break;

	case 5: return "Funk";
		break;

	case 6: return "Grunge";
		break;

	case 7: return "Hip-Hop";
		break;

	case 8: return "Jazz";
		break;

	case 9: return "Metal";
		break;

	case 10: return "New Age";
		break;

	case 11: return "Oldies";
		break;

	case 12: return "Other";
		break;

	case 13: return "Pop";
		break;

	case 14: return "R&B";
		break;

	case 15: return "Rap";
		break;

	case 16: return "Reggae";
		break;

	case 17: return "Rock";
		break;

	case 18: return "Techno";
		break;

	case 19: return "Industrial";
		break;

	case 20: return "Alternative";
		break;

	case 21: return "Ska";
		break;

	case 22: return "Death Metal";
		break;

	case 23: return "Pranks";
		break;

	case 24: return "Soundtrack";
		break;

	case 25: return "Euro-Techno";
		break;

	case 26: return "Ambient";
		break;

	case 27: return "Trip-Hop";
		break;

	case 28: return "Vocal";
		break;

	case 29: return "Jazz+Funk";
		break;

	case 30: return "Fusion";
		break;

	case 31: return "Trance";
		break;

	case 32: return "Classical";
		break;

	case 33: return "Instrumental";
		break;

	case 34: return "Acid";
		break;

	case 35: return "House";
		break;

	case 36: return "Game";
		break;

	case 37: return "Sound Clip";
		break;

	case 38: return "Gospel";
		break;

	case 39: return "Noise";
		break;

	case 40: return "Alternative Rock";
		break;

	case 41: return "Bass";
		break;

	case 42: return "Soul";
		break;

	case 43: return "Punk";
		break;

	case 44: return "Space";
		break;

	case 45: return "Meditative";
		break;

	case 46: return "Instrumental Pop";
		break;

	case 47: return "Instrumental Rock";
		break;

	case 48: return "Ethnic";
		break;

	case 49: return "Gothic";
		break;

	case 50: return "Darkwave";
		break;
	
	case 51: return "Techno-Industrial";
		break;

	case 52: return "Electronic";
		break;

	case 53: return "Pop-Folk";
		break;

	case 54: return "Eurodance";
		break;

	case 55: return "Dream";
		break;

	case 56: return "Southern Rock";
		break;

	case 57: return "Comedy";
		break;

	case 58: return "Cult";
		break;

	case 59: return "Gangsta";
		break;

	case 60: return "Top 40";
		break;

	case 61: return "Christian Rap";
		break;

	case 62: return "Pop/Funk";
		break;

	case 63: return "Jungle";
		break;

	case 64: return "Native US";
		break;

	case 65: return "Cabaret";
		break;

	case 66: return "New Wave";
		break;

	case 67: return "Psychadelic";
		break;

	case 68: return "Rave";
		break;

	case 69: return "Showtunes";
		break;

	case 70: return "Trailer";
		break;

	case 71: return "Lo-Fi";
		break;

	case 72: return "Tribal";
		break;

	case 73: return "Acid Punk";
		break;

	case 74: return "Acid Jazz";
		break;

	case 75: return "Polka";
		break;

	case 76: return "Retro";
		break;

	case 77: return "Musical";
		break;

	case 78: return "Rock & Roll";
		break;

	case 79: return "Hard Rock";
		break;

	case 80: return "Folk";
		break;

	case 81: return "Folk-Rock";
		break;

	case 82: return "National Folk";
		break;

	case 83: return "Swing";
		break;

	case 84: return "Fast Fusion";
		break;

	case 85: return "Bebob";
		break;

	case 86: return "Latin";
		break;

	case 87: return "Revival";
		break;

	case 88: return "Celtic";
		break;

	case 89: return "Bluegrass";
		break;

	case 90: return "Avantgarde";
		break;

	case 91: return "Gothic Rock";
		break;

	case 92: return "Progressive Rock";
		break;

	case 93: return "Psychedelic Rock";
		break;

	case 94: return "Symphonic Rock";
		break;

	case 95: return "Slow Rock";
		break;

	case 96: return "Big Band";
		break;

	case 97: return "Chorus";
		break;

	case 98: return "Easy Listening";
		break;

	case 99: return "Acoustic";
		break;

	case 100: return "Humour";
		break;

	case 101: return "Speech";
		break;

	case 102: return "Chanson";
		break;

	case 103: return "Opera";
		break;

	case 104: return "Chamber Music";
		break;

	case 105: return "Sonata";
		break;

	case 106: return "Symphony";
		break;

	case 107: return "Booty Bass";
		break;

	case 108: return "Primus";
		break;

	case 109: return "Porn Groove";
		break;

	case 110: return "Satire";
		break;

	case 111: return "Slow Jam";
		break;

	case 112: return "Club";
		break;

	case 113: return "Tango";
		break;

	case 114: return "Samba";
		break;

	case 115: return "Folklore";
		break;

	case 116: return "Ballad";
		break;

	case 117: return "Power Ballad";
		break;

	case 118: return "Rhythmic Soul";
		break;

	case 119: return "Freestyle";
		break;

	case 120: return "Duet";
		break;

	case 121: return "Punk Rock";
		break;

	case 122: return "Drum Solo";
		break;

	case 123: return "Acapella";
		break;

	case 124: return "Euro-House";
		break;

	case 125: return "Dance Hall";
		break;

	case 126: return "Goa";
		break;

	case 127: return "Drum & Bass";
		break;

	case 128: return "Club House";
		break;

	case 129: return "Hardcore";
		break;

	case 130: return "Terror";
		break;

	case 131: return "Indie";
		break;

	case 132: return "BritPop";
		break;

	case 133: return "Negerpunk";
		break;

	case 134: return "Polsk Punk";
		break;

	case 135: return "Beat";
		break;

	case 136: return "Christian Gangsta Rap";
		break;

	case 137: return "Heavy Metal";
		break;

	case 138: return "Black Metal";
		break;

	case 139: return "Crossover";
		break;

	case 140: return "Contemporary Christian";
		break;

	case 141: return "Christian Rock";
		break;

	case 142: return "Merengue";
		break;

	case 143: return "Salsa";
		break;
	
	case 144: return "Thrash Metal";
		break;

	case 145: return "Anime";
		break;

	case 146: return "JPop";
		break;

	case 147: return "Synthpop";
		break;

	case 148: return "Rock/Pop";
		break;

	default: return MSG_UNKNOWN_GENRE;
	}
>>>>>>> origin/master:ADT_track.c
}

