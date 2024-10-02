#include<iostream>
using namespace std;

class node{
    public:     
        int data;
        node* left, *right;
        node(int da){
            data=da;
            left=right=NULL;
        }
};
bool isIdentical(node* r1, node* r2){
    if(r1==NULL && r2==NULL)    return true;
    if(r1==NULL && r2!=NULL)    return false;
    if(r1!=NULL && r2==NULL)    return false;

    bool left=isIdentical(r1->left, r2-> left);
    bool right=isIdentical(r1->right, r2-> right);
    bool val= r1->data ==r2->data;
    return left&& right && val; 

}
int main(){
    node* root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);

    node* root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);

    // Check if they are identical
    if(isIdentical(root1, root2)){
        cout << "The trees are identical" << endl;
    } else {
        cout << "The trees are not identical" << endl;
    }

    return 0;
}