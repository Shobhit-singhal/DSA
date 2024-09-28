#include<bits/stdc++.h>
using namespace std;
class nqueue{
    private:
        int n;
        int s;
        int* arr,*front,*rear,*next;
        int freespace;
    public:
        nqueue(int n,int s){
            this->n=n;
            this->s=s;
            arr=new int[s];
            next=new int[s];
            for(int i=0;i<s;i++)
                next[i]=i+1;
            next[s-1]=-1;
            front=new int[n];
            rear=new int[n];
            for(int i=0;i<n;i++){
                front[i]=-1;
                rear[i]=-1;
            }
            freespace=0;
        }
        bool enqueue(int data,int m){
            if(freespace==-1)   return 0;
            int idx=freespace;
            if(front[m-1]==-1)  front[m-1]=idx;
            else next[rear[m-1]]=idx;
            freespace=next[idx];
            next[idx]=-1;
            rear[m-1]=idx;
            arr[idx]=data;
            return 1;
        }
        int deque(int m){
            if(front[m-1]==-1)  return -1;
            int idx=front[m-1];
            front[m-1]=next[idx];
            next[idx]=freespace;
            freespace=idx;
            return arr[idx];
        }
};
int main(){
    nqueue q(3, 10);  // 3 queues with total size 10

    q.enqueue(10, 1);
    q.enqueue(20, 1);
    q.enqueue(30, 2);

    cout << q.deque(1) << endl;  // Outputs 10
    cout << q.deque(2) << endl;  // Outputs 30
    cout << q.deque(1) << endl;  // Outputs 20

    return 0;
}