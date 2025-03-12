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
    int datatype;
    int size;
    
};
struct Node* node_constructor(void* data, int datatype, int size);

#endif