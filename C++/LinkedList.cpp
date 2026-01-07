#include<iostream>
class Node{
    public:
    int val;
    Node* next;
    Node(int data=-1){
        val=data;
        this->next=NULL;
    }
};

class LinkedList{
    public:
    Node* head;
    LinkedList(){
        this->head=NULL;
    }
    void pushFront(int data){
        Node * dummy = new Node(data);
        if(!head){
            head=dummy;
        }
        else{
            dummy->next=head;
            head=dummy;
        }
    }
    void pushBack(int data){
        Node* dummy = new Node(data);
        if(!head){
            head=dummy;
        }
        else{
            Node* temp=head;
            while(!temp->next){
                temp=temp->next;
            }
            temp->next=dummy;
            // dummy->next=NULL;
        }
    }
    void insertAtIndex(int data, int pos){
        Node* temp=head;
        for(int i=0;i<pos-1;i++){
            if(temp->next==NULL){
                std::cout<<"Wrong Position Entered";
                break;
            }
            temp=temp->next;
        }
        Node* dummy = new Node(data);
        dummy->next=temp->next;
        temp->next=dummy;
    }
    void popFront(Node* head){
        Node* temp= head;
        head=head->next;
        free(temp);
    }
    void popBack(Node* head){
        Node* temp=head;
        while(!temp->next){
            temp=temp->next;
        }
        free(temp);
    }
};