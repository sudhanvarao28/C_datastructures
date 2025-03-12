#include "queue.h"
#include<stdio.h>


void push(void* data, int datatype, int size, struct Queue* queue){
    queue->list->insert(queue->list->len, data, datatype, size, queue->list);
}

void* pop(struct Queue* queue){
    void* data = queue->list->get(0, queue->list);
    queue->list->remove_data(0,queue->list);
    return data;
}


struct Queue* queue_constructor(){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->list = linked_list_init(); 

    queue->push = push;
    queue->pop = pop;
    return queue;
}