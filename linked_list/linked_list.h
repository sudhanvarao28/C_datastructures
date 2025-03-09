#ifndef linked_list_h
#define linked_list_h

#include<stdlib.h>
#include "node.h"

struct LinkedList{
    struct Node *head;
    int len;     
    

    void (*insert)(int index, void* value, struct LinkedList*linkedList);
    void (*remove_data)(int index, struct LinkedList*linkedList);
    void*  (*get)(int index, struct LinkedList*linkedList);
};

struct LinkedList* linked_list_init();

#endif