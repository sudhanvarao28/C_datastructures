#include "linked_list.h"

struct Node_int* create_node_int(int data);
void destroy_node_int(struct Node_int* node);
struct Node_int* iterate(int index, struct LinkedList_int* linked_list);
void insert_int(int index, int value, struct LinkedList_int *linkedList);
void remove_int(int index, struct LinkedList_int *linkedList);
int get_node_int(int index, struct LinkedList_int *linkedList);


struct LinkedList_int linked_list_init(){
    struct LinkedList_int new_list;
    new_list.head = NULL;
    new_list.len = 0;

    new_list.insert = insert_int;
    new_list.remove = remove_int;
    new_list.get = get_node_int;
    new_list.constructor = linked_list_init; 

    return new_list;
}


struct Node_int* create_node_int(int data){
    struct Node_int* new_node = (struct Node_int*)malloc(sizeof(struct Node_int));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void destroy_node_int(struct Node_int* node){
        free(node);
}

struct Node_int* iterate(int index, struct LinkedList_int* linked_list){
    if(index >= linked_list->len || index < 0){
        printf("Iterate Error: Index out of bounds");
        exit(-1);
    }
    struct Node_int* cursor = linked_list->head;
    for(int i=0;i<=index;i++){
        cursor = cursor->next;
    }
    return cursor;

}

void insert(int index,int data, struct LinkedList_int* linked_list){
    return;
}