#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

void printList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref;
    Node* prev = NULL;
    if(temp->data==key){
        *head_ref=temp->next;
        delete temp;
        return;
    }
    prev=temp;
    temp=temp->next;
    while(temp!=NULL){
        if(temp->data==key){
            prev->next=temp->next;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    delete temp;
}

void addNodeAtFront(Node** head_ref, int new_data) {
    Node* new_node = NULL;
    new_node = new Node();
    new_node->data=new_data;
    new_node->next=*head_ref;
    *head_ref = new_node;
}

void insertAfter(Node* prev_node, int new_data) {
    Node* new_node;
    new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void addNodeAtEnd(Node* head, int new_data) {
    Node* new_node=NULL;
    new_node = new Node();
    new_node->data=new_data;
    while(true){
        if(head->next==NULL){
            head->next=new_node;
            break;
        }
        head=head->next;
    }
}

void deleteAtPos(Node** head_ref, int position){
    Node* temp = *head_ref;
    if(position==0){
        *head_ref=temp->next;
        delete temp;
    }
    Node* prev = temp;
    temp=temp->next;
    int count=1;
    while(temp!=NULL){
        if(position==count){
            prev->next=temp->next;
        }
        prev=temp;
        temp=temp->next;
        count++;
    }
    delete temp;
}

void deleteLinkedList(Node** head_ref){
    Node* current = *head_ref;
    Node* next;
    while(current!=NULL){
        next=current->next;
        delete current;
        current=next;
    }
    *head_ref = NULL;
}

int listLengthIte(Node* head){
    int length=0;
    while(head!=NULL){
        length++;
        head=head->next;
    }
   return length;
}

int listLengthRec(Node* head){
    if(head==NULL)
        return 0;
    return 1+listLengthRec(head->next);
}

bool existIte(Node* head, int key){
    while(head!=NULL){
        if(head->data==key)
            return true;
        head=head->next;
    }
    return false;
}

bool existRec(Node* head, int key){
    if(head==NULL)
        return false;
    if(head->data==key)
        return true;
    return existRec(head->next, key);
}

int GetNthIte(Node* head, int key){
    int count=0;
    while(head!=0){
        if(count==key)
            return head->data;
        head=head->next;
        count++;
    }
    return -1;
}

int GetNthRec(Node* head, int key){
    if(head==NULL)
        return -1;
    if(key==0)
        return head->data;
    return GetNthRec(head->next, key-1);
}

void reverseIte(Node** head_ref){
    Node* prev = NULL;
    Node* head = *head_ref;
    Node* curr = head;
    Node* next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev=curr;
        curr=next;
    }
    *head_ref=prev;
}

Node* reverseRec(Node* head){
    if(head->next==NULL || head==NULL){
        return head;
    }
    Node* rest = reverseRec(head->next);
    head->next->next=head;
    head->next=NULL;

    return rest;
}

int main(){
    Node* head = NULL;
    Node* second = NULL;
    head = new Node();
    second = new Node();
    head->data=2;
    head->next=second;
    second->data=4;
    printList(head);
    // addNodeAtFront(&head, 1);
    // cout<<endl;
    // printList(head);
    // cout<<endl;
    // insertAfter(head, 3);
    // printList(head);
    cout<<endl;
    addNodeAtEnd(head, 5);
    printList(head);
    // cout<<endl;
    // deleteAtPos(&head, 2);
    // printList(head);
    // deleteLinkedList(&head);
    // cout<<endl<<"linked list Deleted";
    // printList(head);
    // cout<<"\nList length = "<<listLengthIte(head);

    // cout<<endl;
    // cout<<"\nList length = "<<listLengthRec(head);
    // if(existIte(head, 8))
    //     cout<<"exist"<<endl;
    // else
    //     cout<<"do not exist\n";
    // if(existRec(head, 4))
    //     cout<<"exist"<<endl;
    // else
    //     cout<<"do not exist\n";
    // cout<<GetNthIte(head, 2);
    // cout<<GetNthRec(head, 1);
    // reverseIte(&head);
    // cout<<endl;
    head = reverseRec(head);
    cout<<endl;
    printList(head);
    cout<<endl;
    return 0;
}