#include<stdio.h>
#include<stdlib.h>
struct Node
{
    /* data */
    int data;
    struct Node * next;
};

struct Node* insert(int val,struct Node * head){
    struct Node * dummy=(struct Node*)malloc(sizeof(struct Node));
    dummy->data=val;
    dummy->next=NULL;
    if(head==NULL){
        head=dummy;
    }
    else{
        struct Node * temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=dummy;
    }
    return head;
}

void printNode(struct Node * head){
    struct Node * temp=head;
    while (temp!=NULL)
    {
        /* code */
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("Null\n");
}

struct Node * merge(struct Node * head1, struct Node * head2){
    struct Node * temp1=head1;
    struct Node * temp2=head2;
    
}
int main(){
    struct Node * head1=NULL;
    struct Node * head2=NULL;
    // printf("Enter the values to be inserted in Linked List 1:");
    for(int i=0;i<4;i++){
        head1=insert(i+1,head1);
    }
    // printf("Enter the values to be inserted in Linked List 2:");
    for(int i=6;i<10;i++){
        head2=insert(i,head2);
    }
    head1=merge(head1, head2);
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// } *temp = NULL, *first = NULL, *second = NULL, *fhead = NULL, *last = NULL;

// struct Node* Create (int A[], int n)
// {
//     int i;
//     struct Node *t, *last;
//     temp = (struct Node *) malloc(sizeof(struct Node));
//     temp->data = A[0];
//     temp->next = NULL;
//     last = temp;

//     for (i = 1; i < n; i++)
//     {
//         t = (struct Node *) malloc(sizeof(struct Node));
//         t->data = A[i];
//         t->next = NULL;
//         last->next = t;
//         last = t;
//     }
//     return temp;
// }

// void Display(struct Node *p)
// {
//     while (p != NULL)
//     {
//         printf ("%d ", p->data);
//         p = p->next;
//     }
//     printf("\n");
// }

// void Merge(struct Node *first, struct Node *second)
// {
//     if (first->data < second->data)
//     {
//         fhead = last = first;
//         first = first->next;
//         last->next = NULL;
//     }
//     else
//     {
//         fhead = last = second;
//         second = second->next;
//         last->next = NULL;
//     }
    
//     while (first != NULL && second != NULL)
//     {
//         if (first->data < second->data)
//         {
//             last->next = first;
//             last = first;
//             first = first->next;
//             last->next = NULL;
//         }
//         else
//         {
//             last->next = second;
//             last = second;
//             second = second->next;
//             last->next = NULL;
//         }
//     }
    
//     if (first != NULL)
//         last->next = first;
//     else
//         last->next = second;
// }

// int main()
// {
//     int A[] = { 3, 4, 7, 10, 15};
//     int B[] = { 1, 2, 5, 6, 8, 25, 26, 28, 30};
//     first = Create (A, 5);
//     second = Create (B, 9);

//     printf ("1st Linked List: ");
//     Display (first);

//     printf ("2nd Linked List: ");
//     Display (second);

//     Merge (first, second);

//     printf ("\nMerged Linked List: \n");
//     Display (fhead);
//   return 0;
// }