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
};

void Node::display(int level)const{
    if(right){
        right->display(level+1);
    }
    for(int i=0;i<level*4;i++){
        cout << "_";
    }
    cout << data << endl;

    if(left){
        left->display(level+1);
    }
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

    delete root;
    root=nullptr;
    
    return 0;
}