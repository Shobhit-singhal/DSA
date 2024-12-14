#include<bits/stdc++.h>
using namespace std;
class heap{
    public:

        int arr[100];
        int size;
        heap(){
            size=0;
        }
        void insert(int el){
            int idx=++size;
            arr[idx]=el;

            while(idx>1){
                int parent=idx/2;
                if(arr[parent]<arr[idx]){
                    swap(arr[parent],arr[idx]);
                    idx=parent;
                }else
                    return;
            }
        }
        int remove(){
            if(size==0){
                cout<<"Heap is empty"<<endl;
                return;
            }
            int rem=arr[1];
            swap(arr[size--],arr[1]);
            int i=1;
            while(i<=size){
                int left=i*2;
                int right=i*2+1;
                int largest=i;
                if(left<=size && arr[left]>arr[largest]) largest=left;
                if(right<=size && arr[right]>arr[largest])    largest=right;
                if(i!=largest){
                     swap(arr[i],arr[largest]);
                     i=largest;
                }else{
                    break;
                }
            }
            return rem;
        }
        void print(){
            for(int i=1;i<=size;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }

};
int main(){
    heap h1;
    h1.insert(50);
    h1.insert(55);
    h1.insert(53);
    h1.insert(52);
    h1.insert(54);
    h1.print();
    cout<<h1.remove()<<endl;
    cout<<h1.remove()<<endl;
    h1.print();

}