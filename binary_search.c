#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

void tree_display(Node* node,int level){

    if(node!=NULL){
        tree_display(node->right,level+1);
        printf("\n");
        for(int i=0;i<level;i++){
            printf("_");
        }
        printf("%d",node->data);
        tree_display(node->left,level+1);
    }
}

void traverse_preorder(Node* node){ //行きがけ走査
    if(node != NULL){
        printf("%2d ",node->data);
        traverse_preorder(node->left);
        traverse_preorder(node->right);
    }
}

Node* find(Node* node,int data){
    if(node == NULL){
        return NULL;
    }
    if(data < (node->data)){
        return find(node->left,data);
    }
    if(data > (node->data)){
        return find(node->right,data);
    }
    return node;
}

void tree_free(Node* node){
    if(node != NULL){
        tree_free(node->left);
        tree_free(node->right);
        free(node);
    }
}

int main(){
    Node* root;
    Node* node;

    root=malloc(sizeof(Node));
    root->data=40;  

    root->left=malloc(sizeof(Node));
    root->left->data=30;

    root->right=malloc(sizeof(Node));
    root->right->data=70;

    root->left->left=malloc(sizeof(Node));
    root->left->left->data=10;
    root->left->right=NULL;

    root->right->left=malloc(sizeof(Node));
    root->right->left->data=60;
    root->right->left->left=NULL;
    root->right->left->right=NULL;

    root->right->right=malloc(sizeof(Node));
    root->right->right->data=90;
    root->right->right->left=NULL;
    root->right->right->right=NULL;

    root->left->left->left=NULL;
    root->left->left->right=malloc(sizeof(Node));
    root->left->left->right->data=20;
    root->left->left->right->left=NULL;
    root->left->left->right->right=NULL;

    tree_display(root,0);
    printf("\n");

    traverse_preorder(root);
    printf("\n");

    printf("%d を探します\n",70);
    node = find(root,70);
    if(node != NULL){
        printf("見つかりました。%d\n",node->data);
    }
    tree_free(root);

    return 0;
}