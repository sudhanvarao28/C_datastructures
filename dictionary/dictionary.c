#include "dictionary.h"
#include "entry.h"


void insert(struct Dictionary* dictionary, void* key, int key_size, void* value, int value_size);
void* search(struct Dictionary* dictionary, void* key);


struct Dictionary* dictionary_constructor(int (*compare)(void* key_one, void* key_two)){
    struct Dictionary* dictionary = (struct Dictionary*)malloc(sizeof(struct Dictionary));

    dictionary->bst->compare = compare;
    dictionary->insert = insert;
    dictionary->search = search;
    return dictionary;
}

void* search(struct Dictionary* dictionary, void* key){
    void* result = dictionary->bst->search(dictionary->bst,key);
    if(result){
        return ((struct Entry*)result)->value;
    }
    else{
        return NULL;
    }
}

void insert(struct Dictionary* dictionary, void* key, int key_size, void* value, int value_size){
    struct Entry* entry = entry_constructor(key, key_size, value, value_size);
    dictionary->bst->insert(dictionary->bst, entry, sizeof(*entry));
}