#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val) : data(val),next(nullptr){}  //コンストラクタを用意
                    //nextはnullptrで初期化
};

class LinkedList{
    private:
        Node* head;

    public:
        LinkedList() : head(nullptr){} //コンストラクタ

        ~LinkedList(){  //デストラクタを用意
            clear();
        }

        void insert_front(int data);
        void insert_rear(int data);
        void display() const;
        void clear();
};

void LinkedList::insert_front(int data){
    Node* new_node=new Node(data);
    new_node->next=head;
    head=new_node;
}

void LinkedList::insert_rear(int data){
    Node* new_node=new Node(data);
    if(head==nullptr){
        head=new_node;
    }
    else{
        Node* tmp=head;
        while(tmp->next != nullptr){
            tmp=tmp->next;
        }
        tmp->next=new_node;
    }
}

void LinkedList::display()const{
    Node* tmp=head;
    while(tmp != nullptr){
        cout << tmp->data << " ";
        tmp=tmp->next;
    }
    cout << endl;
}

void LinkedList::clear(){
    Node* tmp=head;
    while(tmp != nullptr){
        Node* next_node=tmp->next;
        delete tmp;
        tmp=next_node;
    }
    head=nullptr;
}

int main(){
    LinkedList list;  //headがnullptrで初期化される

    for(int i=1;i<=5;i++){
        list.insert_front(i);
    }

    list.display();

    list.insert_rear(6);
    list.display();

    return 0;
}