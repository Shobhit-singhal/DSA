#include<iostream>
#include<string.h>
using namespace std;
void rev(char ch[],int i,int j){
    if(i<j)
        return;
    swap(ch[i],ch[j]);
    rev(ch,i+1,j-1);
}
int main(){
    char ch[10];
    cin>>ch;
    cout<<ch<<endl;
    cout<<strlen(ch)<<endl;
    cout<<ch[6]<<endl;
    rev(ch,0,strlen(ch)-1);
    cout<<"Rev: "<<ch<<endl;
}