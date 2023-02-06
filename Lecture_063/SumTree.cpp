// Should return true if tree is Sum Tree, else false
class Solution
{
    pair<bool,int> solve(Node*root){
        //you code starts now
        if(root==NULL) return {true,0};
        
        if(root->left==NULL && root->right==NULL) return {true,root->data};
         //else
         pair<bool,int>left=solve(root->left);
         pair<bool,int>right=solve(root->right);
         
         bool l=left.first;
         bool r=right.first;
         bool sum=(left.second+right.second)==root->data;
    //checking for given condition 
         bool resultant=l && r && sum;
    //maintaining sum 
         int resSum=left.second+right.second+root->data;
    //returning ans
         return {resultant,resSum};
    }
    public:
    bool isSumTree(Node* root)
    {
         return solve(root).first;
    }
};