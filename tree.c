#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* create_node(int data){ //ノード作成
    struct Node *node = malloc(sizeof(struct Node));
    if(!node){
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void push_node(struct Node *root, int data){  //ノードを挿入する
    struct Node *temp = root;

    while(1){

        if(temp->data > data){  //親ノードよりも小さい場合
            if(temp->left == NULL){
                temp->left = create_node(data);
                return ;
            }
            temp = temp->left; //左側の子ノードに移動
        }

        else if(temp->data < data){ //親ノードよりも大きい場合
            if(temp->right == NULL){
                temp->right = create_node(data);
                return ;
            }
            temp = temp->right; //右側の子ノードに移動
        }

        else{ //挿入指定データがすでにある場合(重複する場合)
            return ;
        }
    }
}

void preorder(struct Node *node){ //行きがけ順走査
    if(node == NULL){
        return ;
    }
    printf("%d ",node->data);
    preorder(node->left);
    preorder(node->right);
}

void inorder(struct Node *node){  //通りがけ順走査
    if(node == NULL){
        return ;
    }
    inorder(node->left);
    printf("%d ",node->data);
    inorder(node->right);
}

void postorder(struct Node *node){ //帰りがけ順走査
    if(node == NULL){
        return ;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%d ",node->data);
}

void free_tree(struct Node *node){
    if(node == NULL){
        return ;
    }
    //木の削除は帰りがけ順で行う。rootノードを残すため
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

int main(){
    struct Node *root = create_node(40);  //ルートノード40
    int num;
    printf("Please enter 10 numbers\n");
    for(int i = 0; i < 10; i++){
        scanf("%d",&num);
        push_node(root,num);
    }
    printf("\n");

    printf("Preorder  : ");
    preorder(root);
    printf("\n");

    printf("Inorder   : ");
    inorder(root);
    printf("\n");

    printf("Postorder : ");
    postorder(root);
    printf("\n");

    free_tree(root);

    return 0;
}