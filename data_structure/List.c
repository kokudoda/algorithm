#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void linked_list_print(Node* node){
    while(NULL != node){
        printf("%d ",node->data);
        node=node->next;
    }
    printf("\n");
}

int main(){
    Node* head;
    head=malloc(sizeof(Node));
    head->data=300;

    head->next=malloc(sizeof(Node));
    head->next->data=400;

    head->next->next=malloc(sizeof(Node));
    head->next->next->data=500;

    head->next->next->next=malloc(sizeof(Node));
    head->next->next->next->data=600;

    head->next->next->next->next=NULL;
    linked_list_print(head);

    Node* current=head;
    Node* next_node;
    while(current!=NULL){
        next_node=current->next;
        free(current);
        current=next_node;
    }
    return 0;
}