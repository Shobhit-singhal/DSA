#include<iostream>
using namespace std;
int totalDish(int rank,int maxTime){
    int time=0,dish=0;
    while ((time+rank*(dish+1))<=maxTime)
    {
        dish++;
        time+=rank*dish;
        cout<<"preparing dish: "<<dish<<endl;
        cout<<"Total time: "<<time<<endl;
    }
    return dish;
}
int main(){
    cout<<totalDish(4,11)<<endl;
}