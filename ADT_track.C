#include <stdio.h>
#include <string.h>
#include "types.h"
#include "ADT_track.h"

status_t ADT_new_track (FILE* fi, ADT_track_t *track)
{
	

string ADT_genre_to_string (genre_t genre)
{
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
}

int main (int argc, char *argv[])
{
	FILE *fi;
	char input, aux[128];
	size_t i;
	track_t track;

	if((fi=fopen(argv[1], "rb"))==NULL) return 1;

	fseek(fi, OFFSET, SEEK_END);
	fread(aux, TAG_SIZE, 1, fi);
	fread(track.title, FIELD_SIZE, 1, fi);
	fread(track.artist, FIELD_SIZE, 1, fi);
	fread(track.album, FIELD_SIZE, 1, fi);
	fread(aux, FIELD_SIZE+5, 1, fi);
	fread(&track.genre, 1, 1, fi); 

	track.title[FIELD_SIZE]=track.artist[FIELD_SIZE]=track.album[FIELD_SIZE]='\0';

	printf("%s\n\t%s\n\t\t%s\n%i\n", track.artist, track.title, track.album, track.genre);

	fclose(fi);
	return 0;
}
