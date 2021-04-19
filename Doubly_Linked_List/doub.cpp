#include<bits/stdc++.h>
using namespace std;

//Doubly Linked List

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
};

void push(Node** head_ref, int key){
    Node* new_node = NULL;
    new_node = new Node();
    new_node->data=key;
    Node* temp = *head_ref;
    temp->prev=new_node;
    new_node->next = *head_ref;
    *head_ref = new_node;

}
void push_end(Node** head_ref, int key){
    Node* new_node=NULL;
    new_node = new Node();
    new_node->data=key;
    if(*head_ref==NULL){
        *head_ref = new_node;
        return;    
    }
    Node* temp = *head_ref;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->prev=temp;
}
void pushAt(Node** head_ref, int n, int key){
    Node* new_node = NULL;
    // new_node= new Node();
    new_node->data=key;
    Node* temp = *head_ref;
    int count=0;
    if(count==0){
        (*head_ref)->prev=new_node;
        new_node->next=*head_ref;
        *head_ref = new_node;
        return;
    }
    while((count+2)<=n){
        temp=temp->next;
        count++;
    }
    Node* next = temp->next;
    temp->next=new_node;
    new_node->prev=temp;
    new_node->next=next;
    
}
void printList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    Node* head = NULL;
    // head=new Node6();
    // head->data=1;
    // Node* first = NULL;
    // first = new Node();
    // first->data=2;
    // head->next=first;
    // first->prev=head;
    printList(head);
    // Node* head1 = NULL;
    // // head1 = new Node();
    push_end(&head, 3);
    cout<<endl;
    // printList(head);
    // pushAt(&head,0,3);
    printList(head);
    return 0;
}