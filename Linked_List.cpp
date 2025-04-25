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

        void insert_front(int data);  //先頭に挿入
        void insert_rear(int data);   //末尾に挿入
        void delete_front();          //先頭を削除
        void display() const;         //連結リスト表示
        void clear();                 //メモリ開放
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

void LinkedList::delete_front(){
    if(head==nullptr){
        cout << "empty" << endl;
        return ;
    }
    int data=head->data;
    cout << "delete : " << data << endl;
    Node* tmp=head;
    head=head->next;
    delete tmp;
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
        cout << "front insert : " << i << endl;
        list.insert_front(i);
    }

    list.display();

    cout << "end insert : " << 6 <<  endl;
    list.insert_rear(6);
    list.display();

    list.delete_front();

    list.display();

    return 0;
}