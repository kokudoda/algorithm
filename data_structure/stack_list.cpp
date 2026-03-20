#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val) : data(val),next(nullptr){}
};

class stack{
    private:   
        Node* head;
    public:
        stack() : head(nullptr){}
        ~stack(){
            clear();
        }
        void push(int data);
        void pop();
        void display()const;
        void clear();
};

void stack::push(int data){
    Node* new_node=new Node(data);
    new_node->next=head;
    head=new_node; 
}

void stack::pop(){
    if(head==nullptr){
        cout << "empty" << endl;
        return ;
    }
    int data=head->data;
    cout << "POP : " << data << endl;
    Node* tmp=head;
    head=head->next;
    delete tmp;
}

void stack::display()const{
    Node* current = head;
    while(current!=nullptr){
        cout << current->data << " ";
        current=current->next;
    }
    cout << endl;
}   

void stack::clear(){
    Node* current=head;
    Node*next_node;

    while(current != nullptr){
        next_node=current->next;
        delete current;
        current=next_node;
    }
    head=nullptr;
}

int main(){
    stack s;
    for(int i=1;i<=5;i++){
        cout << "PUSH : " << i << endl;
        s.push(i);
    }
    s.display();

    for(int i=0;i<3;i++){
        s.pop();
        s.display();
    }

    return 0;
}