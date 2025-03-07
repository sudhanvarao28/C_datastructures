#include "../linked_list/linked_list.h"
#include <stdio.h>

int main(){
    struct LinkedList_int linked_list = linked_list_init();

    for(int i = 0; i<10; i++){
        linked_list.insert(i,i,&linked_list);
    }
    linked_list.insert(1,99,&linked_list);
    int data = linked_list.get(1,&linked_list);
    printf("Data:%d",data);
    return 0;
}