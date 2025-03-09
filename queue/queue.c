#include "queue.h"


void push(void* data, struct Queue* queue){
    queue->list->insert(queue->list->len, data,queue->list);
}

void* pop(struct Queue* queue){
    void* data = queue->list->get(0, queue->list);
    queue->list->remove_data(0,queue->list);
    return data;
}


struct Queue* queue_constructor(){
    struct Queue* queue;
    queue->list = linked_list_init(); 

    queue->push = push;
    queue->pop = pop;
    return queue;
}