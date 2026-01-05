#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;  //次のノードを指すポインタ
};

struct Node* create_node(int data){  //ノードを作る関数
    struct Node* node = malloc(sizeof(struct Node));  //メモリ確保
    if(!node){
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    
    return node;  //ノードのアドレスを返す
}

//ダブルポインタを使うことでheadが指すノードを変える
void push_front(struct Node** head, int data){
    struct Node* node = create_node(data);
    node->next = *head;
    *head = node;
}

//仮引数がダブルポインタの理由は,head == NULL の場合には先頭に挿入することになり,headをNULLからnodeに変えないといけないから
void push_bottom(struct Node** head,int data){  //末尾に挿入
    struct Node* node = create_node(data);

    if(*head == NULL){  
        *head = node;
        return ;
    }
    struct Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
}

void pop_front(struct Node** head){  //先頭ノードを削除
    if(*head == NULL){
        return ;
    }
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

void show(struct Node* head){
    while(head){
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void free_node(struct Node* head){
    while(head){
        struct Node* temp = head->next;
        free(head);
        head = temp;
    }
}

int main(){
    struct  Node* head = NULL;

    push_front(&head,10);
    push_front(&head,20);
    push_front(&head,30);

    push_bottom(&head,50);
    
    push_front(&head,40);
    show(head);

    pop_front(&head);
    show(head);

    free_node(head);
}