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
};
void insertAtStart(node*& head,int data){
    node* newNode=new node(data);
    newNode->next=head;
    head=newNode;
}

void insertAtTail(node* &tail,int data){
    node* newNode= new node(data);
    tail->next=newNode;
    tail=newNode;
}
void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}


void delStrt(node*& head){
    node*temp=head;
    head=head->next;
    cout<<"Deleted value: "<<temp->data<<endl;
    delete temp;
}

void delEnd(node* head,node*& tail){
    while(head->next!=tail)
        head=head->next;
    cout<<"deleted value: "<<tail->data<<endl;
    delete tail;
    tail=head;
    tail->next=NULL;
}


void delPos(node*& head,node*& tail,int pos){
    if(pos==1){
        delStrt(head);
        return;
    }
    int curr=1;
    node* temp= head;
    while(curr<pos-1){
        temp=temp->next;
        curr++;
    }
    if(temp->next->next==NULL){
        delEnd(head,tail);
        return;
    }
    node* ptr=temp->next;
    cout<<"Deleted value: "<<ptr->data<<endl;
    temp->next=ptr->next;
    delete ptr;
}
void insertMid(node* &head,node* &tail,int data,int pos){
    if(pos==1){
        insertAtStart(head,data);
        return;
    }
    node* temp=head;
    int curr=1;
    while(curr<pos-1){
        temp=temp->next;
        curr++;
    }
    if(temp->next==NULL){
        insertAtTail(tail,data);
        return;
    }
    node* newNode=new node(data);
    newNode->next=temp->next;
    temp->next=newNode;
}


void rev(node* &head,node*& tail){
    node* prev=NULL;
    node* curr=head;
    node* fwd=NULL;
    tail=head;
    while(curr!=NULL){
        fwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fwd;
    }
    head=prev;
}

void delValue(node*& head,node*& tail,int value){
    node* curr=head;
    node*prev;
    while(curr->data!=value){
        prev=curr;
        curr=curr->next;
    }
    if(curr==head){
        delStrt(head);
        return;
    }
    if(curr->next==NULL){
        delEnd(head,tail);
        return;
    }
    prev->next=curr->next;
    cout<<"deleted value: "<<curr->data<<endl;
    delete curr;
}

node* findMid(node*head){
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL)
            fast=fast->next;
        slow=slow->next;
    }
    return slow;
}



void solve(node*& head,node* curr,node*prev){
    if(curr==NULL){
        head=prev;
        return;
    }
    solve(head,curr->next,curr);
    curr->next=prev;
}

node* revRec(node*head,node*& tail){
    tail=head;
    solve(head,head,NULL);
    return head;
}


node* reverse1(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* chotaHead=reverse1(head->next);
    head->next->next=head;
    head->next=NULL;
    return chotaHead;
}


node*reverseInK(node*head,int k){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* prev=NULL;
    node* curr=head;
    node* fwd=NULL;
    int cnt=0;
    while(cnt<k && curr!=NULL){
        fwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fwd;
        cnt++;
    }
    head->next=reverseInK(curr,k);
    return prev;
    
}





bool detectLoop(node*head){
    map<node*,bool> visited;
    node* temp=head;
    while(temp!=NULL){
        if(visited[temp]){
            cout<<"loop at element: "<<temp->data<<endl;
            return 1;
        }
        visited[temp]=1;
        temp=temp->next;
    
    }
    return 0;
}

node* floydDetection(node*head){
    node* fast=head;
    node* slow=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL)
            fast=fast->next;
        slow=slow->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}

node* startingLoop(node*head){
    if(head==NULL)
        return NULL;
    node*fast=floydDetection(head);
    node* slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    // cout<<"loop from: "<<slow->data<<endl;
    return slow;

}

void removeLoop(node* start){
    node*temp=start->next;
    node*prev = start;
    while(temp!=start){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
}





int main(){
    node* node1=new node(3);
    node* head=node1;
    node* tail=node1;

    // insertAtStart(head,2);
    // insertAtStart(head,1);
    // insertAtTail(tail,4);
    // insertAtTail(tail,5);

    insertMid(head,tail,1,1);
    insertMid(head,tail,2,2);
    insertMid(head,tail,4,4);
    print(head);

    // delStrt(head);
    // delEnd(head,tail);


    // delPos(head,tail,2);
    // delPos(head,tail,1);
    // delPos(head,tail,4);


    // delValue(head,tail,2);
    // delValue(head,tail,1);
    // delValue(head,tail,4);


    // rev(head,tail);
    // head=reverseInK(head,3);

    // insertAtTail(tail,5);
    print(head);
    tail->next=head->next;
    node* fast=floydDetection(head);
    if(fast!=NULL){
        node* start=startingLoop(head);
        cout<<"Loop present at: "<<start->data<<endl;
        removeLoop(start);
    }
    else    
        cout<<"no loop present"<<endl;


    print(head);
    // node* mid=findMid(head);
    // cout<<"middle el: "<<mid->data<<endl;;

    cout<<"head: "<<head->data<<" tail: "<<tail->data<<endl; 

}