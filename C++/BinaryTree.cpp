#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node * left;
    Node * right;
    Node(int x){
        this->data=x;
        left=right=NULL;
    }
};

Node * buildTree(){
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    Node * n = new Node (x);
    n->left=buildTree();
    n->right=buildTree();
    return n;
}

void preOrder(Node * root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node * root){
    if(root==NULL){
        return ;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node * root){
    if(root==NULL){
        return ;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(Node * root){
    
}
