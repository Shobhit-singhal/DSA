#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node(int data){
            this->data=data;
            this->next=NULL;
        }
        ~node(){
            cout<<"Deleted: "<<this->data<<endl;
            if(this->next!=NULL){
                delete next;
                this->next=NULL;
            }
        }
};

void insertAtStart(node* &head,int d){
    node* temp=new node(d);
    temp->next=head;
    head=temp;
}

void deleteAtStart(node* &head){
    node* temp=head;
    cout<<"Deleted: "<<temp->data<<endl;;
    head=head->next;
    delete temp;
}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

}

void insertAtTail(node* &tail,int d){
    node* temp=new node(d);
    tail->next=temp;
    tail=tail->next;
}
void insertInMiddle(node* &head,node* &tail,int k,int d){

    if(k==1){
        insertAtStart(head,d);
        return;
    }


    node* ptr=head;
    node* temp=new node(d);
    for(int i=1;i<k-1;i++){
        ptr=ptr->next;
    }

    if(ptr->next==NULL){
        insertAtTail(tail,d);
        return;
    }
    temp->next=ptr->next;
    ptr->next=temp;
}

void delPos(node* &head,node* &tail,int pos){
    
    if(pos==1){
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        node* prev=NULL;
        node*curr=head;
        int cnt=1;
        while(cnt<pos){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        if(curr->next==NULL){
            tail=prev;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }

}


void rev(node* &head,node* &tail){
    node* curr=head;
    node* prev=NULL;
    node* fwd;
    tail=head;
    while(curr!=NULL){
        fwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fwd;
    }
    head=prev;
}


void revRec(node* &head,node* &tail,node* curr,node* prev){
    if(curr==NULL){
        head=prev;
        return;
    }
    revRec(head,tail,curr->next,curr);
    curr->next=prev;
}

node* revLL(node* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    node* tempHead=revLL(head->next);
    head->next->next=head;
    head->next=NULL;
    return tempHead;
}



node* getMiddle(node* head){
    if(head==NULL){
        return head;
    }
    node* fast=head->next;
    node* slow=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL)
            fast=fast->next;
        slow=slow->next;
    }
    return slow;
}


int main(){
    node* node1=new node(3);
    node* head=node1;
    node* tail=node1;
    insertInMiddle(head,tail,2,2);
    insertInMiddle(head,tail,1,1);
    insertAtStart(head,0);
    insertAtTail(tail,4);
    insertAtTail(tail,5);
    print(head);
    cout<<"head: "<<head->data<<"Tail: "<<tail->data<<endl;
    delPos(head,tail,1);
    // delPos(head,tail,5);
    // delPos(head,tail,2);
    print(head);
    cout<<"head: "<<head->data<<"Tail: "<<tail->data<<endl;
    // deleteAtStart(head);
    // print(head);

    node* prev=NULL;
    // revRec(head,tail,head,prev);
    head=revLL(head);
    print(head);


    cout<<getMiddle(head)->data<<endl;
    return 0;
}