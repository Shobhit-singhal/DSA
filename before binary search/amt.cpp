#include<iostream>
using namespace std;
int main(){
    int amt,hund,ten,twenty,one;
    cout<<"Enter the amt: ";
    cin>>amt;
    switch (1)
    {
    case 1:
        hund=amt/100;
         amt=amt%100;
         cout<<hund<<"Rs 100 notes"<<endl;
    case 2:
        twenty=amt/20;
        amt=amt%20;
        cout<<twenty<<"Rs 20 notes"<<endl;
    case 3:
        ten=amt/10;
        amt=amt%10;
        cout<<ten<<"Rs 10 notes"<<endl;
    case 4: 
        one=amt/1;
        amt=amt%1;
        cout<<one<<"Rs one notes"<<endl;
    
    }
}