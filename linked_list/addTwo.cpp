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

void push(Node** head_ref, int new_data) {
    Node* new_node = NULL;
    new_node = new Node();
    new_node->data=new_data;
    new_node->next=*head_ref;
    *head_ref = new_node;
}

void addLinkedLists(Node* head1, Node* head2) {
    int num1=0;
    while(head1!=NULL){
        num1=(head1->data)+num1*10;
        head1=head1->next;
    }
    int num2=0;
    while(head2!=NULL){
        num2=(head2->data)+num2*10;
        head2=head2->next;
    }
    Node* result = NULL;
    result=new Node();
    int res = num1+num2;
    result->data=res%10;
    res=res/10;
    while(res>0){
        push(&result,res%10);
        res/=10;
    }
    cout<<endl;
    printList(result);
}

Node* reverseNth(Node* head, int n){
    Node* prev=NULL;
    Node* curr=head;
    Node* next = NULL;
    int count=0;

    while(count<=n&&curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL)
    head->next=reverseNth(next, n);

    return prev;
}

int main(){
    Node* head1 = NULL;
    Node* head2 = NULL;
    head1=new Node();
    head2 = new Node();
    head1->data=1;
    head2->data=4;

    push(&head1, 2);
    push(&head1, 3);
    push(&head1, 4);
    push(&head1, 5);
    push(&head1, 6);
    push(&head1, 7);
    push(&head1, 8);
    push(&head1, 9);

    // push(&head2, 5);
    // push(&head2, 6);

    // printList(head1);
    // cout<<"\n";
    // printList(head2);
    // cout<<"\n";

    // addLinkedLists(head1, head2);
    printList(head1);
    cout<<"\n";
    Node* res = reverseNth(head1, 5);
    printList(res);
    return 0;
}