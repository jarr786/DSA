class Solution {
    void printleft(Node*root,vector<int>&ans){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL) return;
        //else
        ans.push_back(root->data);
        if(root->left!=NULL){
            printleft(root->left,ans);
        }
        else printleft(root->right,ans);
    }
    void printleaves(Node*root,vector<int>&ans){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL) ans.push_back(root->data);
        //else
        printleaves(root->left,ans);
        printleaves(root->right,ans);  
    }
    void printright(Node*root,vector<int>&ans){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL) return;
        //else
        if(root->right!=NULL){
            printright(root->right,ans);
        }
        else{
            printright(root->left,ans);
        }
        //while retuning 
        ans.push_back(root->data);
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(root==NULL) return ans;
        ans.push_back(root->data);
        //processing other parts
        //left part
        printleft(root->left,ans);
        //leaf node printing
        printleaves(root->left,ans);  //left sub tree 
        printleaves(root->right,ans);  //right sub tree
        //  printing right sub tree
        printright(root->right,ans);
    }
};