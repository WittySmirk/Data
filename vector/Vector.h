#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

#define VECTOR_INITIAL_LIMIT 5

typedef struct VECTOR_STRUCT {
	void** data;
	int limit;
	int count;
	void (*pushBack)(struct VECTOR_STRUCT*, void*);
	void (*fastRemove)(struct VECTOR_STRUCT*, int);
	void (*free)(struct VECTOR_STRUCT*);
}Vector;

void VectorPushBack(Vector* self, void* data) {
    //Resize if needed
    if(self->count == self->limit) {
        self->limit = self->limit * 2;
        self->data = realloc(self->data, sizeof(void*) * self->limit);
    }

    //Add data
    self->data[self->count] = data;
    self->count++;
}

void VectorFastRemove(Vector* self, int index) {
    if(index > -1 && index < self->count) {
        self->data[index] = self->data[self->count - 1];
        self->data[self->count - 1] = NULL;
        self->count--;
    }
}

void VectorFree(Vector* self) {
    if(self->data) {
        free(self->data);
        self->data = NULL;
    }
}

void VectorInit(Vector* vector) {
    vector->limit = VECTOR_INITIAL_LIMIT;
    vector->count = 0;
    vector->pushBack = VectorPushBack;
    vector->fastRemove = VectorFastRemove;
    vector->free = VectorFree;
    vector->data = malloc(sizeof(void*) * vector->limit);
}

#endif