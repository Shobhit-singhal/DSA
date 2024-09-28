#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int decimal,binary=0;
    cout<<"input the number";
    cin>>decimal;
    int mul=1;
    // while (decimal>0)
    // {
    //     binary=(decimal%2*mul)+binary;
    //     // binary=(binary*mul)+decimal%2;
    //     decimal=decimal/2;
    //     mul*=10;
    // }
    if(decimal>0){

        while (decimal>0)
        {
            binary=((decimal&1)*(mul))+binary;
            cout<<(decimal&1)<<endl;
            decimal=decimal>>1;
            mul*=10;
        }
    }else{
        decimal*=-1;
        while (decimal>0)
        {
            // binary=(!(decimal&1)*mul)+binary;
            binary=(binary*10)+!(decimal&1);
            cout<<!(decimal&1)<<endl;
            cout<<binary<<endl;
            mul*=10;
            decimal=decimal>>1;
        }
        
    }
    
    cout<<"binary is: "<<~binary;
    

}