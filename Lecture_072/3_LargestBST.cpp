 
// Qsn-Size of Largest BST in Binary Tree

class info{
 public:
 int maxi;
 int mini;
 bool isbst;
 int size;
};
info solve(TreeNode<int>*root,int &ans){
    //base case
    if(root==NULL) return {INT_MIN,INT_MAX,true,0};

    info left=solve(root->left,ans);
    info right=solve(root->right,ans);

    info result;
    result.size=left.size+right.size+1;
    result.mini=min(root->data,left.mini);
    result.maxi=max(root->data,right.maxi);
    result.isbst=left.isbst && right.isbst && (root->data<right.mini && root->data>left.maxi);

    //update ans
    if(result.isbst==true){
        ans=max(ans,result.size);
    }
    return result;
}
int largestBST(TreeNode<int>* root) 
{
    int ans=0;
    info res=solve(root,ans);
    return ans;
}
