#include<iostream>
using namespace std;
char toLowerCase(char ch){
    if(ch>='a'&&ch<='z'){
        return ch;
    }
    else{
        return ch-'A'+'a';
    }
}
int length(char name[]){
    int count=0;
    for(int i=0;name[i]!='\0';i++){
        count++;
    }
    return count;
}
void rev(char name[],int len){
    int s=0,e=len-1;
    while(s<=e){
        swap(name[s++],name[e--]);
    }
}
bool isPalindrome(char name[],int size){
    int s=0,e=size-1;
    while(s<=e){
        if(toLowerCase(name[s++])!=toLowerCase(name[e--])){
            return 0;
            break;
        }
    }
    return 1;
}
int main(){
    char name[100];
    cout<<"Enter your name: ";
    cin>>name;
    int len=length(name);
    // cout<<"Length is: "<<len<<endl;
    cout<<"Palindrome or not: "<<isPalindrome(name,len)<<endl;

    rev(name,len);
    cout<<"Rev is: "<<name<<endl;

    cout<<"S to lower case:"<<toLowerCase('S')<<endl;
    cout<<"s to lower case:"<<toLowerCase('s');
}