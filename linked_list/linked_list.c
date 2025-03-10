#include<stdio.h>
#include "linked_list.h"

struct Node* create_node(void* data);
void destroy_Node(struct Node* node);
struct Node* iterate(int index, struct LinkedList* linked_list);
void insert(int index, void* value, struct LinkedList *linkedList);
void remove_data(int index, struct LinkedList *linkedList);
void* get_node_data_int(int index, struct LinkedList *linkedList);


struct LinkedList* linked_list_init(){
    struct LinkedList* new_list = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    new_list->head = NULL;
    new_list->len = 0;

    new_list->insert = insert;
    new_list->remove_data = remove_data;
    new_list->get = get_node_data_int;

    return new_list;
}


struct Node* create_node(void* data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void destroy_Node(struct Node* node){
        free(node);
}

struct Node* iterate(int index, struct LinkedList* linked_list){
    if(index >= linked_list->len || index < 0){
        printf("Iterate Error: Index out of bounds");
        exit(-1);
    }
    
    struct Node* cursor = linked_list->head;
    for(int i=0;i<index;i++){
        cursor = cursor->next;
    }
    return cursor;

}

void insert(int index,void* data, struct LinkedList* linked_list){
    struct Node* node_to_insert = create_node(data);
    
    if(index == 0){
        node_to_insert->next = linked_list->head;
        linked_list->head = node_to_insert;
    }
    else{
        
        struct Node* old_node = iterate(index-1,linked_list);
        node_to_insert->next = old_node->next; 
        old_node->next = node_to_insert;
    }
    linked_list->len+=1;
}

void remove_data(int index, struct LinkedList* linked_list){
    if(index == 0){
        struct Node* node_to_remove = linked_list->head;
        linked_list->head = node_to_remove->next;
        destroy_Node(node_to_remove);
    }
    else{
        struct Node* old_node = iterate(index-1,linked_list);
        struct Node* node_to_remove = old_node->next;
        old_node->next = node_to_remove->next;
        destroy_Node(node_to_remove);
    }
    linked_list->len-=1;

}

void* get_node_data_int(int index, struct LinkedList* linked_list){
    struct Node* node = iterate(index,linked_list);
    return node->data;

}