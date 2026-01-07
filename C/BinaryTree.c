#include<stdio.h>
#include<stdlib.h>
struct Node{
    char data;
    struct Node * left;
    struct Node * right;
};
struct Node * createNode(){
    char x;
    scanf("%c",&x);
    if(x=='*'){
        return NULL;
    }
    struct Node * n= (struct Node*)malloc(sizeof(struct Node));
    n->data=x;
    n->left=createNode();
    n->right=createNode();
    return n;
}

void preOrder(struct Node * root){
    if(root==NULL){
        return ;
    }
    printf("%c ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node * root){
    if(root==NULL){
        return ;
    }
    inOrder(root->left);
    printf("%c ",root->data);
    inOrder(root->right);
}

void postOrder(struct Node * root){
    if(root==NULL){
        return ;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ",root->data);
}
int main(){
    struct Node *root = createNode();
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);

    
}