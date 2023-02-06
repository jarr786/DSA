// Should return  right view of tree
class Solution
{
    public:
    void solve(Node*root,int level,vector<int>&ans){
    if(root==NULL) return;
    //main condition u will understand when u make a dry and run on copy
    if(ans.size()==level){
        ans.push_back(root->data);
    }
    // else make a call by increasing the level
    solve(root->right,level+1,ans);
    solve(root->left,level+1,ans);
}
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector<int>ans;
   int level=0;
   solve(root,level,ans);
   return ans;
    }
};