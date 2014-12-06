/*************************prototipos*************************/
status_t	ADT_new_track (FILE*, ADT_track_t**);
status_t	ADT_destroy_track (void**);
status_t	ADT_get_author (const ADT_track_t*, string*);
status_t	ADT_get_title (const ADT_track_t*, string*);
status_t	ADT_get_genre (const ADT_track_t*, genre_t*);
int		ADT_cmp_author (const void*, const void*);
int		ADT_cmp_title (const void*, const void*);
int		ADT_cmp_genre (const void*, const void*);
status_t	ADT_print_track_as_csv (FILE*, void*);
status_t	ADT_print_track_as_string (FILE*, void*);
string		ADT_genre_to_string (genre_t);
/*************************prototipos*************************/

