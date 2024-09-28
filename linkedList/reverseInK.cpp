#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int d){
        this->data=d;
        this->next=NULL;
    }
};

void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

node* revInK(node* head, int k){
    if(head==NULL){
        return NULL;
    }


    node* curr=head;
    node* prev=NULL;
    node* fwd=NULL;
    int cnt=0;
    while (curr!=NULL && cnt<k  )
    {
        fwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fwd;
        cnt++;
    }
    
    if(fwd!=NULL){
        head->next=revInK(fwd,k);
    }
    return prev;
}

bool isCircular(node* head){
    // Write your code here.
if(head==NULL)
        return true;

    node* temp=head->next;

    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    if(temp==head)
        return true;
    return false;
    
}
int main(){
    node* head=new node(1);
    node* ptr=head;
    for(int i=2;i<=10;i++){
        node* nd1=new node(i);
        ptr->next=nd1;
        ptr=ptr->next;
    }
    print(head);
    // revInK(head,2);
    // print(head);
    cout<<isCircular(head);

}