#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Node * insertAtBegin(struct Node * head, int x){
    struct Node * dummy=(struct Node *) malloc(sizeof(struct Node));
    dummy->data=x;
    if(head==NULL){
        head=dummy;
        dummy->next=dummy;
    }
    else if(head->next==head){
        dummy->next=head;
        head->next=dummy;
        head=dummy;
    }
    else{
        struct Node * prt =head->next;
        while(prt->next!=head){
            prt=prt->next;
        }
        dummy->next=head;
        head=dummy;
        prt->next=dummy;
    }
    return head;
}

struct Node * insertAtEnd(struct Node * head, int x){
    struct Node * dummy=(struct Node *) malloc(sizeof(struct Node));
    dummy->data=x;
    if(head==NULL){
        head=dummy;
        dummy->next=dummy;
    }
    else if(head->next==head){
        dummy->next=head;
        head->next=dummy;
    }
    else{
        struct Node * ptr=head->next;
        while (ptr->next!=head)
        {
            ptr=ptr->next;
        }
        dummy->next=head;
        ptr->next=dummy;
    }
    return head;

}

struct Node * deleteAtBegin(struct Node * head){
    if(head==NULL){
        printf("Empty");
    }
    else if(head->next==head){
        free(head);
        head=NULL;
    }
    else{
        struct Node * ptr=head->next;
        while(ptr->next!=head){
            ptr=ptr->next;
        }
        struct Node * temp= head;
        head=head->next;
        ptr->next=head;
        free(temp);
    }
    return head;
}

struct Node * deleteAtEnd(struct Node * head){
    if(head==NULL){
        printf("Empty");
    }
    else if(head->next==head){
        free(head);
    }
    else{
        struct Node * ptr=head->next;
        while(ptr->next->next!=head){
            ptr=ptr->next;
        }
        struct Node * temp= ptr->next;
        ptr->next=head;
        free(temp);
    }
    return head;
}


void print(struct Node * head){
    struct Node * temp=head;
    do
    {
        printf("%d",temp->data);
        temp=temp->next;
    } while (temp!=head);
    
}

int main(){
    struct Node * head=NULL;
    // head=insertAtBegin(head,3);
    // // print(head);
    // head=insertAtBegin(head,4);
    // print(head);
    // printf("\n");
    // head=insertAtBegin(head,2);
    // print(head);
    // printf("\n");
    // head=insertAtBegin(head,1);
    // print(head);

    head=insertAtEnd(head,1);
    // print(head);
    head=insertAtEnd(head,2);
    // print(head);
    head=insertAtEnd(head,3);
    print(head);

    head=deleteAtEnd(head);
    print(head);
}