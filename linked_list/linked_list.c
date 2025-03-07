#include<stdio.h>
#include "linked_list.h"

struct Node_int* create_node_int(int data);
void destroy_node_int(struct Node_int* node);
struct Node_int* iterate(int index, struct LinkedList_int* linked_list);
void insert_int(int index, int value, struct LinkedList_int *linkedList);
void remove_int(int index, struct LinkedList_int *linkedList);
int get_node_data_int(int index, struct LinkedList_int *linkedList);


struct LinkedList_int linked_list_init(){
    struct LinkedList_int new_list;
    new_list.head = NULL;
    new_list.len = 0;

    new_list.insert = insert_int;
    new_list.remove_int = remove_int;
    new_list.get = get_node_data_int;

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

void insert_int(int index,int data, struct LinkedList_int* linked_list){
    struct Node_int* node_to_insert = create_node_int(data);
    if(index == 0){
        node_to_insert->next = linked_list->head;
        linked_list->head = node_to_insert;
    }
    else{
        
        struct Node_int* old_node = iterate(index-1,linked_list);
        node_to_insert->next = old_node->next; 
        old_node->next = node_to_insert;
    }
    linked_list->len+=1;
}

void remove_int(int index, struct LinkedList_int* linked_list){
    if(index == 0){
        struct Node_int* node_to_remove = linked_list->head;
        linked_list->head = node_to_remove->next;
        destroy_node_int(node_to_remove);
    }
    else{
        struct Node_int* old_node = iterate(index-1,linked_list);
        struct Node_int* node_to_remove = old_node->next;
        old_node->next = node_to_remove->next;
        destroy_node_int(node_to_remove);
    }
    linked_list->len-=1;

}

int get_node_data_int(int index, struct LinkedList_int* linked_list){
    struct Node_int* node = iterate(index,linked_list);
    return node->data;

}