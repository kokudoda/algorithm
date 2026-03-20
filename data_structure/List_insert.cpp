#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
}Node;

void insert(Node** head,int data){    //関数内でポインタの値を書き換えるため、ダブルポインタにする
    Node* new_node = new Node;
    new_node->data=data;  //new_nodeというポインタが指している構造体のdataメンバにdataを代入している
    
    if(*head==nullptr){  //空の状態
        new_node->next=nullptr;  //new_node → nullptr となる
        *head=new_node;         // head → new_node → nullptr となる
    }
    else{
        new_node->next=*head; //headポインタが今指している要素(つまり先頭の要素)を指すようにするため
        *head=new_node;       
    }

}
void link_print(Node* node){
    while(node != nullptr){
        cout << node->data << " ";
        node=node->next;
    }
}

int main(){
    Node* head;  //構造体Node へのポインタ

    head=nullptr;

    for(int i=1;i<=5;i++){
        printf("insert : %d\n",i);
        insert(&head,i);
    }

    link_print(head);

    Node* current=head;
    Node* next_node;

    while(current != nullptr){
        next_node=current->next;
        delete current;
        current=next_node;
    }
    return 0;
}