#include<stdio.h>
using namespace std;


struct LknkedList {
    int data;
    struct LinkedList *next;

};

typedef struct LinkedList *node;

node createNode() {
    node temp;
    temp = (node)malloc(sizeof(struct LinkedList));
    temp->next = NULL;
    return temp;
}

node addNode(node head, int data){
    node temp,p;
    temp = createNode();
    temp->data = data;
    if(head == NULL){
        head = temp;
    }
    else{
        p = head;
        while(p->next != NULL){
            p = p->next;
        
        }
        p->next = temp;
    }
    return head ;
}


int main() {
    //TODO: complete the code;
}
