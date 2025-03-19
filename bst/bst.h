#ifndef bst_h
#define bst_h

#include "../node/node.h"

struct BinarySearchTree{
    struct Node* head;

    int(*compare)(void* data1, void* data2);
    void* (*search)(struct BinarySearchTree* bst, void* data);
    void(*insert)(struct BinarySearchTree* bst, void* data, int size);
    
};
struct BinarySearchTree* bst_constructor(int (*compare)(void* data1, void* data2));
#endif