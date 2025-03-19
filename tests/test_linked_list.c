#include "../linked_list/linked_list.h"
#include "../queue/queue.h"
#include <stdio.h>
#include <string.h>

int main(){

    //create linked list
    struct LinkedList* linked_list = linked_list_init();

    //put data into linked list via for loop
    for(int i = 0; i<10; i++){
        int* x = (int* )malloc(sizeof(int));
        *x = i;
        linked_list->insert(i,x,1,linked_list);
    }

    //insert data into a specified place in linked list
    char* num = (char*)malloc(strlen("Sudhanva") + 1);
    strcpy(num, "Sudhanva");
    linked_list->insert(2,num,strlen(num)+1,linked_list);

    //print data
    int len = linked_list->len;
    for(int i = 0;i<len;i++){
        if(i==2){
            printf("Data:%s\n",(char*)linked_list->get(i,linked_list));
        }
        else{
        printf("Data:%d\n",*(int*)linked_list->get(i,linked_list));
        }
    }
    free(num);
    printf("\n");

    // remove data    
    linked_list->remove_data(3, linked_list);

    //print data
    len = linked_list->len;
    for(int i = 0;i<len;i++){
        printf("Data:%d\n",*(int*)linked_list->get(i,linked_list));
    }
    
    //create new queue
    struct Queue* new_queue = queue_constructor();

    printf("\n");
    //push data to the queue
    for(int i = 0; i<10; i++){
        int* x = (int* )malloc(sizeof(int));
        *x = i;
        new_queue->push(x,1,new_queue);
    }

    printf("\n");
    
    
    //pop data from the queue and display
    for(int i = 0;i<10;i++){
        printf("Data in Queue:%d\n",*(int*)new_queue->pop(new_queue));
    }


    
    return 0;
}