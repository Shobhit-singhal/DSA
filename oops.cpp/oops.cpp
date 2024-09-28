#include<iostream>
#include<string.h>
using namespace std;

class user{
    private:
        string pwd;
    public:
        char *name;
        int age;
        // static string org="MICROSOFT";
        static string org;
        static int time;
        int id;
        string username;
        user(int age,int id){
            name=new char[100];
            this->age=age;
            this->id=id;
        }

        user(user& temp){
            this->age=temp.age;
            this->id=temp.id;
            this->username=temp.username;
            char *ch=new char[100];
            this->name=ch;
        }
        void setPwd(string pwd){
            this->pwd=pwd;
        }
        void setUsername(string username){
            this->username=username;
        }
        string getUsername(){
            return this->username;
        }
        string getPwd(){
            return this->pwd;
        }
        void setName(char n[]){
            // char *temp=new char[strlen(n)+1];
            strcpy(this->name,n);
            // this->name=temp;
            // this->name=n;
        }

        void print(){
            cout<<"Username: "<<this->username<<endl;
            cout<<"Age: "<<this->age<<endl;
            cout<<"Id: "<<this->id<<endl;
            cout<<"Name: "<<this->name<<endl;
            cout<<"Dont tell anyone about this:\n";
            cout<<"Pwd: "<<this->pwd<<endl<<endl;;
        }
        static int printTime(){
            // cout<<org<<endl;
            return time;
        }
};

string user::org="MICROSOFT";
int user::time=5;
int main(){

    cout<<user::org<<endl;
    cout<<user::printTime<<endl;
    user u1(18,2545);
    char name[8]="shobhit";
    u1.setName(name);
    u1.age=19;
    u1.setPwd("shobhit");
    u1.setUsername("shobhit");
    u1.print();

    user *u2=new user(20,1234);
    u2->age=5;
    u2->setPwd("abc123");
    u2->setUsername("random");
    u2->print();


    user *u3=new user(u1);
    u3->setPwd("random");
    u3->print();

    // u1.print();


    return 0;
}