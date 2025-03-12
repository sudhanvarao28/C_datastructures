#include "node.h"


struct Node* node_constructor(void* data, int datatype, int size){
    if(size<1){
        printf("Invalid Size for Node.........");
        exit(1);
    }

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    switch (datatype) {
        case Int: {
            node->data = malloc(sizeof(int) * size);
            for (int i = 0; i < size; i++) {
                ((int*)node->data)[i] = ((int*)data)[i];
            }
        } break;

        case Long: {
            node->data = malloc(sizeof(long) * size);
            for (int i = 0; i < size; i++) {
                ((long*)node->data)[i] = ((long*)data)[i];
            }
        } break;

        case Float: {
            node->data = malloc(sizeof(float) * size);
            for (int i = 0; i < size; i++) {
                ((float*)node->data)[i] = ((float*)data)[i];
            }
        } break;

        case Double: {
            node->data = malloc(sizeof(double) * size);
            for (int i = 0; i < size; i++) {
                ((double*)node->data)[i] = ((double*)data)[i];
            }
        } break;

        case Char: {
            node->data = malloc(sizeof(char) * size);
            for (int i = 0; i < size; i++) {
                ((char*)node->data)[i] = ((char*)data)[i];
            }
        } break;

        case Bool: {
            node->data = malloc(sizeof(bool) * size);
            for (int i = 0; i < size; i++) {
                ((bool*)node->data)[i] = ((bool*)data)[i];
            }
        } break;

        default: {
            node->data = data;
        } break;
    }
node->datatype = datatype;
node->size = size;
node->next = NULL;
return node;

}