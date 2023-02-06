class Solution{          //this is the optimized solution
    public:
    pair<bool,int> solve(Node*root){
        if(root==NULL) return {true,0};
        //else
        pair<bool,int>left=solve(root->left);
        pair<bool,int>right=solve(root->right);
        //
        bool l=left.first;
        bool r=right.first;
        bool diff=abs(left.second-right.second)<=1;
        bool result=l && r && diff;
        
        int h=max(left.second,right.second)+1;
        //make pair
        pair<bool,int>ans;
        ans.first=result;
        ans.second=h;
        return ans;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return solve(root).first;
    }
};