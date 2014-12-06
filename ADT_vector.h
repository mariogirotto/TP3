#include <stdio.h>

#define INIT_CHOP 20
#define CHOP_SIZE 10
		
typedef struct {
		size_t size;
		void ** elements;
		size_t alloc_size;
		} ADT_vector_t;


