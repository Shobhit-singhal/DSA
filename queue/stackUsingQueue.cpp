#include<bits/stdc++.h>
using namespace std;
class myStack{
    private:
        queue<int> q1;
        queue<int> q2;
    public:
        void push(int x){
            q2.push(x);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            swap(q1,q2);
        }
        void pop(){
            if(!q1.empty())
                q1.pop();
            else 
                cout<<"stack overflow"<<endl;
        }
        int top(){
            return (q1.empty())?-1:q1.front();
        }
        bool empty(){
            return q1.empty();
        }
};
int main(){
    myStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element is: " << s.top() << endl; // 30
    s.pop();
    cout << "Top element after pop is: " << s.top() << endl; // 20
    return 0;
}