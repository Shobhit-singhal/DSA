#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;
        heap(){
            arr[0]=-1;
            size=0;
        }

        void insert(int val){
            int idx=++size;
            arr[idx]=val;
            while(idx>1){
                int parent=idx/2;
                if(arr[parent]< arr[idx]){
                    swap(arr[parent],arr[idx]);
                    idx=parent;
                }else{
                    return;
                }
            }
        }
        int del(){
            if(size==0){
                cout<< "nothing to delete"<<endl;
                return -1;
            }
            int ret=arr[1];
            arr[1]=arr[size--];
            int idx=1;
            while(idx<=size){
                int left=idx*2;
                int right=idx*2+1;
                int larger=idx;
                if(left<=size && arr[left]>arr[larger])
                    larger=left;
                if(right<=size && arr[right]>arr[larger])
                    larger=right;

                if(larger!=idx){
                    swap(arr[idx],arr[larger]);
                    idx=larger;
                }else{
                    break;
                }
            }
            return ret;
        }
        void print(){
            for(int i=1;i<=size;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
};

int main(){
   heap h;
    
    // Insert test values
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);

    // Print initial heap
    cout << "Heap after insertions: ";
    h.print();  // Should print: 30 20 5 10

    // Test delete operations
    cout << "Deleted element: " << h.del() << endl;  // Should delete 30
    cout << "Heap after deleting max: ";
    h.print();  // Should print: 20 10 5

    cout << "Deleted element: " << h.del() << endl;  // Should delete 20
    cout << "Heap after deleting max: ";
    h.print();  // Should print: 10 5

    cout << "Deleted element: " << h.del() << endl;  // Should delete 10
    cout << "Heap after deleting max: ";
    h.print();  // Should print: 5

    cout << "Deleted element: " << h.del() << endl;  // Should delete 5
    cout << "Heap after deleting max: ";
    h.print();  // Should print nothing (heap is empty)



    cout<<"using stl:"<<endl<<endl;

    priority_queue<int> maxheap;
    maxheap.push(3);
    maxheap.push(5);
    maxheap.push(7);
    maxheap.push(4);
    maxheap.push(9);

    cout<<maxheap.top()<<endl;
    maxheap.pop();
    cout<<maxheap.top()<<endl;
    cout<<"Size of the heap: "<<maxheap.size()<<endl;

    cout<<"\n\nMin heap:"<<endl<<endl;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    minHeap.push(3);
    minHeap.push(5);
    minHeap.push(7);
    minHeap.push(4);
    minHeap.push(9);

    cout<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<minHeap.top()<<endl;
    cout<<"Size of the heap: "<<minHeap.size()<<endl;


    return 0;
}