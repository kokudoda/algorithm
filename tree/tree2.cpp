#include <iostream>
using std::cin;
using std::cout;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int num) : data(num),left(nullptr),right(nullptr){}
};

class Tree{
    private:
        Node* root;
    
        //クラスの外から呼ばれたくないため、再帰処理がある関数はprivateに

        void preorder_impl(Node* node); //行きがけ順走査
        void inorder_impl(Node* node); //通りがけ順走査
        void postorder_impl(Node* node); //帰りがけ順走査
        Node* find_impl(Node* node,int key);  //探索する関数
        void delete_tree(Node* node); //ノードを開放する関数

    public:
        Tree() : root(nullptr){}
        ~Tree(){
            delete_tree(root);  //再帰処理の関数を呼び出すための関数
        }
        void insert(int num); //挿入する関数
        
        //再帰処理の関数を呼び出すための関数↓
        void preorder() { preorder_impl(root);}
        void inorder() { inorder_impl(root);}
        void postorder() { postorder_impl(root);}
        Node* find(int key) { return find_impl(root,key);}
};

void Tree::insert(int num)
{
    if(root == nullptr){
        root = new Node(num);
        return ;
    }
    Node* node = root;

    while(1){
        //挿入したい数値がdataよりも小さい場合
        if(node->data > num){   
            //左の子ノードが空の場合
            if(node->left == nullptr){ 
                node->left = new Node(num);
                return ;
            }
            node = node->left;      //左の子ノードに更新
        }
        //挿入したい数値がdataよりも大きい場合
        else if(node->data < num){
            //右の子ノードが空の場合
            if(node->right == nullptr){
                node->right = new Node(num);
                return ;
            }
            node = node->right;     //右の子ノードに更新
        }
        else{   //挿入したい数値がすでにある場合)
            return ;
        }
    }
}

// private //
//行きがけ走査
void Tree::preorder_impl(Node* node)
{
    if(node == nullptr){
        return ;
    }
    cout << node->data << " ";
    preorder_impl(node->left);
    preorder_impl(node->right);
}

//通りがけ順走査
void Tree::inorder_impl(Node* node)
{
    if(node == nullptr){
        return ;
    }
    inorder_impl(node->left);
    cout << node->data << " ";
    inorder_impl(node->right);
}


//帰りがけ順走査
void Tree::postorder_impl(Node* node)
{
    if(node == nullptr){
        return ;
    }
    postorder_impl(node->left);
    postorder_impl(node->right);
    cout << node->data << " ";
}

//探索する関数
Node* Tree::find_impl(Node* node,int key)
{
    if(node == nullptr){    //見つからなかった場合
        return nullptr;
    }
    if(node->data > key){   //数値よりも小さかった場合
        return find_impl(node->left,key);
    }
    if(node->data < key){   //数値よりも大きかった場合
        return find_impl(node->right,key);
    }
    return node;    //見つかったら返す
}

void Tree::delete_tree(Node* node)
{
    if(node == nullptr){    //木が空の場合
        return ;
    }
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

int main()
{
    Tree tree;
    int num,key;

    cout << "挿入したい数値を入力してください(終了は-1)" << "\n";
    while(true){
        cin >> num;
        if(num == -1){
            break;
        }
        tree.insert(num);
    }

    cout << "Preorder : " ;
    tree.preorder();
    cout << "\n";

    cout << "Inorder : " ;
    tree.inorder();
    cout << "\n";

    cout << "Postorder : ";
    tree.postorder();
    cout << "\n";

    cout << "探したい値を入力してください >> ";
    cin >> key;
    Node* node = tree.find(key);
    if(node != nullptr){
        cout << "[" << node->data << "] found" << "\n";
    }
    else{
        cout << "Not found" << "\n";
    }

    return 0;
}