#ifndef dictionary_h
#define dictionary_h

#include "../bst/bst.h"
#include "entry.h"

struct Dictionary{
    struct BinarySearchTree* bst;

    void (*insert)(struct Dictionary* dictionary, void* key, int key_size, void* value, int value_size);
    void* (*search)(struct Dictionary* dictionary, void* key);
};

struct Dictionary* dictionary_constructor(int (*compare)(void* key_one, void* key_two));
void dictionary_destructor(struct Dictionary* dictionary);

#endif