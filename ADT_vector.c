#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"
#include "ADT_vector.h"
#include "ADT_vector_prototypes.h"

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
 
	if(p == NULL||destructor ==NULL) return ERROR_NULL_POINTER;
	
	for(i=0; i<((*p)->size); i++)
		if ((st=(*destructor)(&((*p)->elements[i]))) != OK) return st;
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

status_t ADT_vector_append_element (ADT_vector_t * p, void * new_element, status_t (*destructor)(void**))
{

	void ** aux;

	if (p == NULL || new_element == NULL) return ERROR_NULL_POINTER;

	if (p->elements == NULL)
	{
		if ((p->elements = (void **) malloc (INIT_CHOP * sizeof (void*)))==NULL)
			return ERROR_MEMORY;	
		p -> alloc_size = INIT_CHOP;
	}
	else if (p->alloc_size == p->size)
	{
		if((aux = (void**) realloc (p->elements, (p->alloc_size + CHOP_SIZE) * sizeof (void*))) == NULL)
		{
			ADT_vector_delete (&p, destructor);
			return ERROR_MEMORY;
		}
		p->alloc_size += CHOP_SIZE;
		p->elements = aux;
	}
	p->elements[p->size++] =  new_element;
	return OK;
}
			 	

bool_t ADT_vector_is_empty (ADT_vector_t *p)
{
	if ((p->size) == 0) return TRUE;
	return FALSE;
}

size_t ADT_vector_get_size (ADT_vector_t *p)
{	
	if (p == NULL) return -1;
	return(p->size);
}

status_t ADT_print_vector (ADT_vector_t *p, status_t (*printer)(FILE *, void*), FILE* fo)
{
	int i;
	status_t st;	
	
	if (p == NULL || printer == NULL || fo == NULL) return ERROR_NULL_POINTER;
	
	for(i=0; i<(p->size); i++)
		if ((st=(*printer)(fo, &(p->elements[i]))) != OK) return st;
		fputc('\n', fo);
	
	return OK;
}


