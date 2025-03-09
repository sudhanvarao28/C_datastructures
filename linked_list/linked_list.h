#ifndef linked_list_h
#define linked_list_h

#include<stdlib.h>
#include "node.h"

struct LinkedList_int{
    struct Node_int *head;
    int len;     
    

    void (*insert)(int index, void* value, struct LinkedList_int *linkedList);
    void (*remove_int)(int index, struct LinkedList_int *linkedList);
    void*  (*get)(int index, struct LinkedList_int *linkedList);
};

struct LinkedList_int* linked_list_init();

#endif