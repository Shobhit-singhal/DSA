#include<iostream>
using namespace std;
int main(){
    char op;
    int n1,n2;
    cout<<"Enter two numbers: ";
    cin>> n1>>n2;
    cout<<"Enter the operator: ";
    // op=cin.get();
    cin>>op;
    switch (op)
    {
    case '+':
        cout<<n1+n2<<endl;
        break;
    case '-':
        cout<<n1-n2<<endl;
        break;
    case '*':
        cout<<n1*n2<<endl;
        break;
    case '/':
        cout<<n1/n2<<endl;
        break;
    default:
        cout<<"invalid"<<endl;
        break;
    }
}