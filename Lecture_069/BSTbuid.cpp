#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};
// building a tree from the input given by the user
node* insertIntoBST(node*root,int d){
    if(root==NULL){
        root=new node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertIntoBST(root->right,d);
    }
    else{
        root->left=insertIntoBST(root->left,d);
    }
    return root;
}
void takeInput(node*&root){
    int data;
    cout<<"enter data : ";
    cin>>data;
    cout<<endl;
    while(data!=-1){
        root=insertIntoBST(root,data);
        cout<<"enter another data : ";
        cin>>data;
        cout<<endl;
    }
}
  void printInOrder(node* root)
    {  
         if(root==NULL){
            return;
         }
         printInOrder(root->left);
         cout<<root->data<<" ";
         printInOrder(root->right);
    }
int main(){
    node*root=NULL;
    cout<<"enter data to create BST :";
    cout<<endl;
    takeInput(root);
    printInOrder(root);
return 0;
}