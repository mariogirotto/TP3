/*************************prototipos*************************/
status_t ADT_vector_new (ADT_vector_t ** p);
status_t ADT_vector_delete (ADT_vector_t ** p, status_t (*destructor)(void**));
status_t ADT_vector_append_element (ADT_vector_t * p, void * new_element, status_t (*destructor)(void**));
bool_t ADT_vector_is_empty (ADT_vector_t *p);
size_t ADT_vector_get_size (ADT_vector_t *p);
status_t ADT_print_vector (ADT_vector_t *p, status_t (*printer)(FILE *, void*), FILE* fo);
/*************************prototipos*************************/
