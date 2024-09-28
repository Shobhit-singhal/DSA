#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
};
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* getMid(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}


Node* merge(Node* left,Node* right){
    Node* dummy=new Node(-1);
    Node* ptr=dummy;
    Node* newNode=NULL;
    while(left!=NULL && right!=NULL){
        if(left->data<=right->data){
            newNode=new Node(left->data);
            ptr->next=newNode;
            ptr=ptr->next;
            left=left->next;
        }
        else{
            newNode=new Node(right->data);
            ptr->next=newNode;
            ptr=ptr->next;
            right=right->next;
        }
    }
    while(left!=NULL){
        newNode=new Node(left->data);
        ptr->next=newNode;
        ptr=ptr->next;
        left=left->next;
    }
    while(right!=NULL){
        newNode=new Node(right->data);
        ptr->next=newNode;
        ptr=ptr->next;
        right=right->next;
    }
    return dummy->next;
}
Node* mergeSort(Node* head){
    if(head==NULL || head->next==NULL)
        return head;
    
    Node* mid=getMid(head);
    Node* left=head;
    Node* right=mid->next;
    mid->next=NULL;
    left=mergeSort(left);
    right=mergeSort(right);
    Node* ans=merge(left,right);
    return ans;
}
int main(){
    Node* head=new Node(5);
    head->next=new Node(60);
    head->next->next=new Node(1);
    head->next->next->next=new Node(9);
    print(head);
    head=mergeSort(head);
    print(head);
}