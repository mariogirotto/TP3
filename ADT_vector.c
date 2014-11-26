#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_CHOP 20

/*typedef struct {

		
		}destructor_t;
*/

typedef enum {
		TRUE,
		FALSE
		} bool_t;
		
typedef enum {
		OK,
		ERROR_NULL_POINTER,
		ERROR_MEMORY
		} status_t;

typedef struct {
		size_t size;
		void * elements;
		size_t alloc_size;
		/*typedef status_t (destructor_t)(void *) destructor;*/
		} ADT_vector_t;

status_t ADT_vector_new (ADT_vector_t ** p)
{
	if (p == NULL) return ERROR_NULL_POINTER;

	if ((*p =(ADT_vector_t *) malloc (sizeof (ADT_vector_t))) == NULL)
		return ERROR_MEMORY;
	if(((*p)->elements = (void**) malloc (INIT_CHOP * sizeof (void *))) == NULL)
	{
		free (*p);
		(*p) = NULL;
		return ERROR_MEMORY;
	}
	(*p)->alloc_size = INIT_CHOP; 
	(*p)->size = 0;
	/*(*p)->destructor = NULL;*/
	return OK;
}

status_t ADT_vector_delete (ADT_vector_t ** p, status_t (*destructor)(void**))
{
	size_t i;
	status_t st;
 
	if(p == NULL) return ERROR_NULL_POINTER;
	
	for(i=0; i<((*p)->size); i++)
		if ((st=(*destructor)(&((*p)->elements[i]))) != OK) return st; /**((*p)->destructor))*/
	free ((*p) -> elements);
	(*p) -> elements = NULL;
	free (*p);
	(*p) = NULL;
	return OK;
}

/*status_t ADT_vector_set_destructor (ADT_vector_t *p, destructor_t pf)
{
	if (p == NULL) return ERROR_NULL_POINTER;
	p->destructor = pf;
	return OK;
}
*/

bool_t ADT_vector_is_empty (ADT_vector_t *p)
{
	if (((*p).size) == 0) return TRUE;
	return FALSE;
}

size_t ADT_vector_get_size (ADT_vector_t *p)
{	
	if (p == NULL) return -1;
	return((*p).size);
}

