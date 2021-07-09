#include<stdio.h>
#include<stdlib.h>

#define HEAD arr[0]

struct node {
    int data;
    struct node *next;

};
typedef struct node node;

void printLinkedlist(struct node *p) {
    while (p != NULL) {
        printf(" %d ", p->data);
        p = p->next;
    }
}

int main()
{
    int y = 7474,i =0;
    node *arr[y] ;//array of node pointers


    for( i = 0; i< y; i++) {
        arr[i] = NULL;
        if(i != 0) {
            arr[i] = (node*)malloc(sizeof(node));


        }

    }
    int x = 1;//skipping arr[0] AKA head
    while(x< y) {
        arr[x]->data = x;

        x++;
    }
    int r= 1;//skipping arr[0] AKA head
    while(r< y-1/*last node's linking address will be NULL*/) {
        arr[r]->next = arr[r + 1];

        r++;
    }
    
    arr[r] = NULL;
    HEAD = arr[1];//setting arr[1] as head




    printf("[");
    printLinkedlist(HEAD);
    printf("]");
    return 0;
}
