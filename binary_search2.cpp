#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) : data(val),left(nullptr),right(nullptr){}  //コンストラクタ

        ~Node(){  //デストラクタ.再帰的にメモリを解放
            delete left;
            delete right;
        }
        void display(int level=0)const;
        void traverse_pre()const;  //行きがけ順走査
        void traverse_in()const;   //通りがけ順走査
        void traverse_po()const;   //帰りがけ順走査
};

void Node::display(int level)const{
    if(right){
        right->display(level+1);
    }
    for(int i=0;i<level*2;i++){
        cout << "_";
    }
    cout << data << endl;

    if(left){
        left->display(level+1);
    }
}

void Node::traverse_pre()const{
    cout << data << " ";
    if(left){
        left->traverse_pre();
    }
    if(right){
        right->traverse_pre();
    }
}

void Node::traverse_in()const{
    if(left){
        left->traverse_in();
    }
    cout << data << " ";
    if(right){
        right->traverse_in();
    }
}

void Node::traverse_po()const{
    if(left){
        left->traverse_po();
    }
    if(right){
        right->traverse_po();
    }
    cout << data << " ";
}

int main(){
    Node* root=new Node(40);
    root->left=new Node(30);
    root->right=new Node(70);

    root->left->left=new Node(10);
    root->left->left->right=new Node(20);

    root->right->left=new Node(60);
    root->right->right=new Node(90);

    root->display();
    cout << endl;

    cout << "行きがけ順走査 : ";
    root->traverse_pre();
    cout << endl;

    cout << "通りがけ順走査 : ";
    root->traverse_in();
    cout << endl;

    cout << "帰りがけ順走査 : ";
    root->traverse_po();
    cout << endl;

    delete root;
    root=nullptr;

    return 0;
}