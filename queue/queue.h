#ifndef queue_h
#define queue_h

#include "../linked_list/linked_list.h"

struct Queue{
    struct LinkedList* list;

    void (*push)(void* data, int datatype, int size, struct Queue* queue);
    void* (*pop)(struct Queue* queue);
};

struct Queue* queue_constructor();


#endif
