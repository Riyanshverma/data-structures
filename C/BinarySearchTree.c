#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * insert(struct Node * root, int x){
    if(root==NULL){
        struct Node * dummy = (struct Node *) malloc(sizeof(struct Node));
        dummy->data=x;
        dummy->left=NULL;
        dummy->right=NULL;
        return dummy;
    }
    if(x<root->data){
        root->left=insert(root->left,x);
    }
    else{
        root->right=insert(root->right,x);
    }
    return root;

}

struct Node * search(struct Node * root, int key){
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

int findMin(struct Node * root){
    root=root->right;
    while (root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}

struct Node * delete(struct Node * root, int key){
    if(root==NULL){
        return NULL;
    }
    else if(key<root->data){
        root->left=delete(root->left,key);
        return root;
    }
    else if(key>root->data){
        root->right=delete(root->right,key);
        return root; 
    }
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        if(root->left!=NULL && root->right==NULL){
            struct Node * temp=root->left;
            free(root);
            return temp;
        }
        if(root->right!=NULL && root->left==NULL){
            struct Node * temp =root->right;
            free(root);
            return temp; 
        }
        else{
            int min= findMin( root);
            root->data=min;
            root->right=delete(root->right,min);
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
    struct Node * root =NULL;
    root=insert(root,8);
    root=insert(root,4);
    root=insert(root,1);
    root=insert(root,7);
    root=insert(root,10);
    root=insert(root,9);
    root=insert(root,11);

    // inOrder(root);

    

    root = delete(root,8);
    inOrder(root);
    printf("1.Insert\n2.Delete\n3.Search\n4.Print\n5.Exit");
    int choice;
    scanf("Enter your choice %d",&choice);
    do{
        switch(choice){
            case 1:
                int val;
                scanf("Enter the value:%d",&val);
                root=insert(root,val);
                break;
            case 2:
                int val;
                scanf("Enter the value%d",&val);
                root=delete(root,val);
                break;
            case 3:
                struct Node * temp = search(root,10);
                if(temp){
                    printf("%d",temp->data);
                }
                else{
                    printf("No");
                }

        }
    }while(choice!=5);

}