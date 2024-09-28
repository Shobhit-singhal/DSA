#include<iostream>
using namespace std;
int main(){
    printf("hello world\n");
    int decimal=0,binary;
    cout<<"input binary: ";
    cin>>binary;
    int mul=1;
    while (binary>0){
        decimal=(binary%10)*mul+decimal;
        mul*=2;
        binary=binary/10;
    }
    cout<<"the decimal is: "<<decimal;


}