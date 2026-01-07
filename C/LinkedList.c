#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void insertAtBegin(int val)
{
    struct Node *dummy = (struct Node *)malloc(sizeof(struct Node));
    dummy->data = val;
    // dummy->next=NULL;
    if (head == NULL)
    {
        head = dummy;
    }
    else
    {
        dummy->next = head;
        head = dummy;
    }
}
void insertAtEnd(int val)
{
    struct Node *dummy = (struct Node *)malloc(sizeof(struct Node));
    dummy->data = val;
    dummy->next=NULL;
    if (head == NULL)
    {
        head = dummy;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = dummy;
    }
}
void insertAtMiddle(int val, int pos)
{
    if (pos == 0)
    {
        insertAtBegin(val);
    }
    else
    {
        struct Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp->next == NULL)
            {
                printf("Wrong Position Entered\n");
                break;
            }
            temp = temp->next;
        }
        struct Node *dummy = (struct Node *)malloc(sizeof(struct Node));
        dummy->data = val;
        dummy->next = temp->next;
        temp->next = dummy;
    }
}
void deleteAtBegin()
{
    if (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        printf("Empty List\n");
    }
}
void deleteAtEnd()
{
    if (head != NULL)
    {
        struct Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        struct Node *dummy = temp->next;
        temp->next = NULL;
        free(dummy);
    }
    else
    {
        printf("Empty List\n");
    }
}
void deleteAtIndex(int pos)
{
    if (pos == 0)
    {
        deleteAtBegin();
    }
    else
    {
        struct Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp->next == NULL)
            {
                printf("Wrong Position Entered\n");
                break;
            }
            temp = temp->next;
        }
        struct Node *flag = temp->next;
        temp->next = flag->next;
        free(flag);
    }
}


void printList(struct Node *head){
    struct Node * temp=head;
    while(temp){
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    deleteAtBegin();
    deleteAtEnd();

    // Inserting at the beginning:

    for (int i = 0; i < 5; i++)
    {
        insertAtBegin(i + 1);
    }

    // Inserting at the end:

    for (int i = 0; i > -5; i--)
    {
        insertAtEnd(i);
    }

    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
    deleteAtBegin();
    deleteAtBegin();
    deleteAtBegin();
    deleteAtEnd();
    deleteAtEnd();
    temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
    insertAtMiddle(-3, 2);
    temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
    deleteAtIndex(1);
    deleteAtIndex(1);
    deleteAtIndex(1);
    temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
    printList(head);
}