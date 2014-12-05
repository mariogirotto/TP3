#include <stdio.h>

#define INIT_CHOP 20

		
typedef struct {
		size_t size;
		void * elements;
		size_t alloc_size;
		/*typedef status_t (*destructor_t)(void *) destructor;*/
		} ADT_vector_t;

