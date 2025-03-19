#ifndef node_h
#define node_h

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

enum datatype{
    Special,
    Int,
    Long,
    Float,
    Double,
    Char,
    Bool

};

struct Node{
    void *data;
    struct Node *next;
    struct Node *previous;
    
};
struct Node* node_constructor(void* data, int size);

#endif