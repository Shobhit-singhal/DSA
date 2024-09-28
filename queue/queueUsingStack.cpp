#include<bits/stdc++.h>
using namespace std;
class myQueue{
    private:
        stack<int> s1;
        stack<int> s2;
    public:
        void push(int x){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        void pop(){
            if(!s1.empty())
                s1.pop();
            else    cout<<"Underflow"<<endl;
        }
        int front(){
            return (s1.empty())?-1:s1.top();
        }
        bool empty(){
            return s1.empty();
        }
};
int main(){
        myQueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Front element is: " << q.front() << endl; // 10
    q.pop();
    cout << "Front element after pop is: " << q.front() << endl; // 20
    return 0;
}