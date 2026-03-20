#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void linked_list_print(Node* node){
    while(node != nullptr){
        cout << node->data << " ";
        node=node->next;
    }
    cout << endl;
}

int main(){
    Node* head=new Node;
    head->data=300;

    // head → [300] 

    head->next=new Node;
    head->next->data=400;

    // head → [300] → [400] 

    head->next->next=new Node;
    head->next->next->data=500;

    // head → [300] → [400] → [500] 

    head->next->next->next=new Node;
    head->next->next->next->data=600;

    //head → [300] → [400] → [500] → [600] 

    head->next->next->next->next=nullptr;

    // head → [300] → [400] → [500] → [600] → nullptr  今はこの状態

    linked_list_print(head);

    Node* current=head; 
    // head → [300] → [400] → [500] → [600] → nullptr
     //current_↑  cuurentは今300を指している

    Node* next_node;  //次のノードへのポインタ,が失われないようにするために一時的に退避させる用
    
    while(current != nullptr){
        next_node = current->next; //次のノードを指す
        delete current;            //メモリ解放
        current = next_node;      //次のノードを指す
    }
    return 0;
}