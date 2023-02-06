 class Solution {
  public:
  pair<int,int> solve(Node*root){
      if(root==NULL){
           pair<int,int>p=make_pair(0,0);
           return p;
       }
       pair<int,int>left=solve(root->left);
       pair<int,int>right=solve(root->right);
       //diameter process
       int l=left.first;
       int r=right.first;
       int d=left.second+right.second+1;
       //height process
       int h=max(left.second,right.second)+1;
       //returning process
       pair<int,int>ans;
       ans.first=max(l,max(r,d));
       ans.second=h;
       return ans;
  }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
       return solve(root).first;
    }
};