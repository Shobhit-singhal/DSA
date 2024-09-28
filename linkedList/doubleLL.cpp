#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* prev;
        node* next;
        node(int data){
            this->data=data;
            this->next=NULL;
            this->prev=NULL;
        }
        ~node(){
            cout<<"Deleted: "<<this->data<<endl;
            if(this->next==NULL){
                delete next;
            }
        }
};
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertAtHead(node* &head,int d){
    node* temp=new node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertAtTail(node* &tail,int d){
    node *temp=new node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
int getLength(node* &head){
    node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

void insertAtPos(node* &head,node* &tail,int pos,int d){
    if(pos==1){
        insertAtHead(head,d);
    }
    else{
        node*ptr=head;
        int curr=1;
        while(curr<pos-1){
            curr++;
            ptr=ptr->next;
        }
        if(ptr->next==NULL){
            insertAtTail(tail,d);
        }
        else{
            node* temp=new node(d);
            temp->next=ptr->next;
            temp->next->prev=temp;
            ptr->next=temp;
            temp->prev=ptr;
        }
    }
}

void printRev(node* &tail){
    node* temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }cout<<endl;
}
void deleteAtPos(node*&head,node*&tail,int pos){
    if(pos==1){
        node *temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        temp->prev=NULL;
        delete temp;
    }
    else{
        int cnt=1;
        node* curr=head;
        node* last=NULL;
        while (cnt<pos)
        {
            last=curr;
            curr=curr->next;
            cnt++;
        }
        last->next=curr->next;
        if(curr->next==NULL){
            tail=last;
        }else{
        last->next->prev=last;
        }
        curr->next=NULL;
        curr->prev=NULL;
        delete curr;
    }
    
}
int main(){
    node* node1=new node(1);
    node* head=node1;
    node* tail=node1;
    // print(head);
    int length=getLength(head);
    cout<<length<<endl;
    // insertAtHead(head,0);
    // insertAtHead(head,-1);
    // insertAtHead(head,-2);
    // insertAtTail(tail,2);
    // insertAtTail(tail,3);
    insertAtPos(head,tail,1,0);
    insertAtPos(head,tail,2,2);
    insertAtPos(head,tail,4,7);
    // insertAtPos(head,tail,2,3);
    print(head);
    printRev(tail);
    deleteAtPos(head,tail,4);
    print(head);
    printRev(tail);
    cout<<"Head: "<<head->data<<" Tail: "<<tail->data<<endl;

}