#include<bits/stdc++.h>
using namespace std;

//Circular Linked List

class Node {
    public:
        int data;
        Node* next;
};

void printList(Node* head){
    Node* temp = head;
    while(true){
        cout<<head->data<<" ";
        if(head->next==temp)
            break;
        head=head->next;
    }
}

void push_end(Node** head_ref, int key){
    Node* new_node = NULL;
    new_node = new Node();
    new_node->data=key;
    if((*head_ref)==NULL){
        *head_ref = new_node;
        (*head_ref)->next=*head_ref;
        return;
    }
    Node* temp = *head_ref;
    while(temp->next!=(*head_ref)){
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->next=*head_ref;
}   

int main(){
    Node* head = NULL;
    push_end(&head,1);
    push_end(&head,2);
    push_end(&head,3);
    printList(head);
    
    
    cout<<endl;
    return 0;
}