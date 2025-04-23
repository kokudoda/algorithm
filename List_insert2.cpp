#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}  //コンストラクタ　dataとnextを初期化
}Node;

void insert(int data,Node** node){
    Node* new_node=new Node;
    new_node->data=data;

    if(*node==nullptr){
        new_node->next=nullptr;
        *node=new_node;
    }
    else{
        new_node->next=*node;
        *node=new_node;
    }
}

void rear_insert(int data,Node** node){  //末尾への挿入
    Node* new_node=new Node;
    new_node->data=data;
    new_node->next=nullptr;

    //この時点で新たに末尾になるノードはnullptrを指せており、dataメンバも格納出来ている状態
    //あとは挿入前の末尾のnode->nextがnew_nodeを指せるようにすればよい

    if(*node==nullptr){ //空の時 head →　nukkptr　の状態
        *node=new_node;   //head → new_node →　nukkptr となる
    }
    else{
        Node* rear=*node;
        while(rear->next != nullptr){ //末尾までたどる
            rear=rear->next; 
        }
        rear->next=new_node;
    }

}
void link_print(const Node* node){  
    while(node != nullptr){
        cout << node->data << " ";
        node=node->next;
    }
    cout << endl;
}

int main(){
    Node* head=nullptr;

    for(int i=1;i<=5;i++){
    cout << "insert" << i << endl;
    insert(i,&head);
    }

    link_print(head);

    rear_insert(6,&head);

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