#include "node.h"
#include <stdlib.h>
#include<string.h>


struct Node* node_constructor(void* data, int size){
    if(size<1){
        printf("Invalid Size for Node.........");
        exit(1);
    }

struct Node* node = (struct Node*)malloc(sizeof(struct Node));
node->data = malloc(size);
memcpy(node->data, data, size);     
node->next = NULL;
node->previous = NULL;
return node;

} 