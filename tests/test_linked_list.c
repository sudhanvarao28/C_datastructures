#include "../linked_list/linked_list.h"
#include <stdio.h>

int main(){
    struct LinkedList_int* linked_list = linked_list_init();

    for(int i = 0; i<10; i++){
        int* x = (int* )malloc(sizeof(int));
        *x = i;
        linked_list->insert(i,x,linked_list);
    }
    int* num = (int*)malloc(sizeof(int));


    *num = 77;
    linked_list->insert(2,num,linked_list);


    int len = linked_list->len;
    for(int i = 0;i<len;i++){
        printf("Data:%d\n",*(int*)linked_list->get(i,linked_list));
    }
    printf("\n");
    linked_list->remove_int(3, linked_list);

    len = linked_list->len;
    for(int i = 0;i<len;i++){
        printf("Data:%d\n",*(int*)linked_list->get(i,linked_list));
    }
    
    
    return 0;
}