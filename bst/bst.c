#include "bst.h"


struct Node* create_node(void* data, int size);
void destroy_Node(struct Node* node);
void* search(struct BinarySearchTree* bst, void* data);
void insert(struct BinarySearchTree* bst, void* data, int size);


struct BinarySearchTree* bst_constructor(int(*compare)(void* data1, void* data2)){
    struct BinarySearchTree* bst = (struct BinarySearchTree*)malloc(sizeof(struct BinarySearchTree));
    bst->compare = compare;
    bst->insert = insert;
    bst->search = search;
    return bst;
}


struct Node* create_node(void* data, int size){
    // struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // new_node->data = data;
    // new_node->next = NULL;
    struct Node* new_node = node_constructor(data, size);
    return new_node;
}

void destroy_Node(struct Node* node){
        free(node);
}

struct Node* iterate(struct BinarySearchTree* bst, struct Node* cursor, void* data, int* direction){
    if(bst->compare(cursor->data,data) == 1){
        if(cursor->next){
            iterate(bst, cursor->next, data, direction);
        }
        else{
        *direction = 1;
        return cursor;    
        }
    }
    else if(bst->compare(cursor->data,data) == -1){
        if(cursor->previous){
            iterate(bst, cursor->previous, data, direction);
        }
        else {
        *direction = -1;
        return cursor;
        }
    }
    else{
        *direction=0;
        return cursor;
    }
}

void* search(struct BinarySearchTree* bst, void* data){
    int* direction;
    struct Node* node = iterate(bst, bst->head, data, direction);
    if(*direction == 0){
        return node->data;
    }
    else{
        return NULL;
    }
}

void insert(struct BinarySearchTree* bst, void* data, int size){
    int* direction;
    struct Node* node = iterate(bst, bst->head, data, 0);
    if(*direction == 1){
        node->next = create_node(data, size);
    }
    else if (*direction == -1) {
        node->previous = create_node(data, size);
    }
}