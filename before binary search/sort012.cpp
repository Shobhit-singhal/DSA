#include<iostream>
using namespace std;
void print(int arr[],int size){
    for(int i=0;i<size;i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
}
void sort012(int arr[],int size){
    int i=0,j=0,k=size-1;
    int st=0;
    while (j<=k)
    {
        cout<<"step:"<<(st++)<<endl<<"i: "<<i<<"   j= "<<j<<"   k:"<<k<<endl;
            print(arr,size);
            cout<<endl;
            
        if(arr[i]==0 || arr[k]==2){
            if(arr[i]==0)
            i++;
            if(arr[k]==2)
            k--;
        }else{
            if(arr[j]==0){
                swap(arr[i],arr[j]);
                i++;
                j++;
            }else if(arr[j]==2){
                swap(arr[j],arr[k]);
                // j++;
                k--;
            }
            else
            j++;
        }
    }
    cout<<"final ans is:"<<endl<<endl;
    print(arr,size);
    


}
int main(){
    // int size,arr[100];
    // cout<<"Enter the size of arr: ";
    // cin>>size;
    int arr[100]={1,0,2,0,2,1,0,0,1};
    int size=9;

    sort012(arr,size);
}