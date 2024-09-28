#include<iostream>
#include<vector>
using namespace std;
char toLower(char ch){
    if((ch>='a'&& ch<='z')||(ch>='0' && ch<='9'))
        return ch;
    return ch-'A'+'a';
}
bool isValid(char ch){
    // cout<<"checking : "<<ch<<endl;
    if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
        // cout<<"valid: "<<ch<<endl;
        return 1;
    }
    return 0;
}
bool isPalindrome(string s) {
    int i=0;
    string temp;
    int len=s.length();
    while(i<len){
        // cout<<"Looop: "<<endl;
        
        if(isValid(s[i])){ 
            temp.push_back(s[i++]);
        }
        else{
            i++;
        }
    }
    cout<<temp<<endl;
    int a=0,b=temp.length()-1;
    while(a<=b){
        if(toLower(temp[a++])!=toLower(temp[b--])){
            cout<<"a: "<<temp[a]<<"b: "<<temp[b]<<endl;
            cout<<"not equal: "<<temp[a]<<" and "<<toLower(temp[b])<<endl;
        return 0;
        }
    }
    return 1;
}

char maxOcc(string s){
    int len=s.length();
    vector<int> v(26,0);
    int ch;
    for(int i=0;i<len;i++){
        if((s[i]>='a'&& s[i]<='z'))
            ch=s[i]-'a';
        else{
            ch=s[i]-'A';
        };
        v[ch]++;
    }
    int maxi=-1;
    for(int i=0;i<v.size();i++){
        if(v[i]>maxi)
        maxi=i;
    }
    cout<<char(maxi+'a');
}
int main(){
    maxOcc("Shobhit");
}
