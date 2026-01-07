#include<iostream>
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

Node * insert(Node * root, int key){
    if(root==NULL){
        return new Node(key);
    }
    if(key<root->data){
        root->left=insert(root->left,key);
    }
    else{
        root->right=insert(root->right,key);
    }
    return root;
}

Node * search(Node * root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(key<root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}

int findMin(Node * root){
    root=root->right;
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}

Node * remove(Node * root, int key){
    if(root==NULL){
        return NULL;
    }
    if(key<root->data){
        root->left=remove(root->left,key);
        return root;
    }
    if(key>root->data){
        root->right=remove(root->right,key);
        return root;
    }
    else{
        if(root->left==NULL && root->right==NULL){
            delete(root);
            return NULL;
        }
        if(root->left!=NULL && root->right==NULL){
            Node * temp = root->left;
            delete(root);
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){
            Node * temp = root->right;
            delete(root);
            return temp;
        }
        else{
            int minval=findMin(root);
            root->data=minval;
            root->right=remove(root->right,minval);
            return root;
        }
    }
}

void inOrder(struct Node * root){
    if(root==NULL){
        return ;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

int main(){
    Node * root=NULL;
    root=insert(root,8);
    root=insert(root,4);
    root=insert(root,1);
    root=insert(root,7);
    root=insert(root,10);
    root=insert(root,9);
    root=insert(root,11);

    inOrder(root);

    // Node * temp = search(root,10);
    // if(temp){
    //     printf("%d",temp->data);
    // }
    // else{
    //     printf("No");
    // }

    root = remove(root,4);
    inOrder(root);

}