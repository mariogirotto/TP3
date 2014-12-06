#include <stdio.h>
#include <stdlib.h>

#define TITLE_FIELD_SIZE 30
#define AUTHOR_FIELD_SIZE 30
#define CSV_SEPARATOR '|'
#define TAG_SIZE 3
#define TITLE_OFFSET -125
#define GENRE_OFFSET -1
#define MSG_UNKNOWN_GENRE "Genero desconocido"

typedef enum {
	BLUES=0,
	CLASSIC_ROCK=1,
	COUNTRY=2,
	DANCE=3,
	DISCO=4,
	FUNK=5,
	GRUNGE=6,
	HIP_HOP=7,
	JAZZ=8,
	METAL=9,
	NEW_AGE=10,
	OLDIES=11,
	OTHER=12,
	POP=13,
	RANDB=14,
	RAP=15,
	REGGAE=16,
	ROCK=17,
	TECHNO=18,
	INDUSTRIAL=19,
	ALTERNATIVE=20,
	SKA=21,
	DEATH_METAL=22,
	PRANKS=23,
	SOUNDTRACK=24,
	EURO_TECHNO=25,
	AMBIENT=26,
	TRIP_HOP=27,
	VOCAL=28,
	JAZZ_FUNK=29,
	FUSION=30,
	TRANCE=31,
	CLASSICAL=32,
	INSTRUMENTAL=33,
	ACID=34,
	HOUSE=35,
	GAME=36,
	SOUND_CLIP=37,
	GOSPEL=38,
	NOISE=39,
	ALTERNATIVE_ROCK=40,
	BASS=41,
	SOUL=42,
	PUNK=43,
	SPACE=44,
	MEDITATIVE=45,
	INSTRUMENTAL_POP=46,
	INSTRUMENTAL_ROCK=47,
	ETHNIC=48,
	GOTHIC=49,
	DARKWAVE=50,
	TECHNO_INDUSTRIAL=51,
	ELECTRONIC=52,
	POP_FOLK=53,
	EURODANCE=54,
	DREAM=55,
	SOUTHERN_ROCK=56,
	COMEDY=57,
	CULT=58,
	GANGSTA=59,
	TOP_40=60,
	CHRISTIAN_RAP=61,
	POP_FUNK=62,
	JUNGLE=63,
	NATIVE_US=64,
	CABARET=65,
	NEW_WAVE=66,
	PSYCHADELIC=67,
	RAVE=68,
	SHOWTUNES=69,
	TRAILER=70,
	LO_FI=71,
	TRIBAL=72,
	ACID_PUNK=73,
	ACID_JAZZ=74,
	POLKA=75,
	RETRO=76,
	MUSICAL=77,
	ROCK_AND_ROLL=78,
	HARD_ROCK=79,
	FOLK=80,
	FOLK_ROCK=81,
	NATIONAL_FOLK=82,
	SWING=83,
	FAST_FUSION=84,
	BEBOB=85,
	LATIN=86,
	REVIVAL=87,
	CELTIC=88,
	BLUEGRASS=89,
	AVANTGARDE=90,
	GOTHIC_ROCK=91,
	PROGRESSIVE_ROCK=92,
	PSYCHEDELIC_ROCK=93,
	SYMPHONIC_ROCK=94,
	SLOW_ROCK=95,
	BIG_BAND=96,
	CHORUS=97,
	EASY_LISTENING=98,
	ACOUSTIC=99,
	HUMOUR=100,
	SPEECH=101,
	CHANSON=102,
	OPERA=103,
	CHAMBER_MUSIC=104,
	SONATA=105,
	SYMPHONY=106,
	BOOTY_BASS=107,
	PRIMUS=108,
	PORN_GROOVE=109,
	SATIRE=110,
	SLOW_JAM=111,
	CLUB=112,
	TANGO=113,
	SAMBA=114,
	FOLKLORE=115,
	BALLAD=116,
	POWER_BALLAD=117,
	RHYTHMIC_SOUL=118,
	FREESTYLE=119,
	DUET=120,
	PUNK_ROCK=121,
	DRUM_SOLO=122,
	ACAPELLA=123,
	EURO_HOUSE=124,
	DANCE_HALL=125,
	GOA=126,
	DRUM_AND_BASS=127,
	CLUB_HOUSE=128,
	HARDCORE=129,
	TERROR=130,
	INDIE=131,
	BRITPOP=132,
	NEGERPUNK=133,
	POLSK_PUNK=134,
	BEAT=135,
	CHRISTIAN_GANGSTA_RAP=136,
	HEAVY_METAL=137,
	BLACK_METAL=138,
	CROSSOVER=139,
	CONTEMPORARY_CHRISTIAN=140,
	CHRISTIAN_ROCK=141,
	MERENGUE=142,
	SALSA=143,
	THRASH_METAL=144,
	ANIME=145,
	JPOP=146,
	SYNTHPOP=147,
	ROCK_POP=148
} genre_t;

typedef struct {
	char *title, *author;
	genre_t genre;
} ADT_track_t;

