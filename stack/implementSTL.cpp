#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int> st;
    cout<<"Is empty?: "<<st.empty()<<endl;

    st.push(1);
    st.push(2);
    cout<<"Top: "<<st.top()<<endl;
    st.pop();
    cout<<"Top: "<<st.top()<<endl;

    cout<<"Size: "<<st.size()<<endl;
    cout<<"Empty or not: "<<st.empty()<<endl;

}