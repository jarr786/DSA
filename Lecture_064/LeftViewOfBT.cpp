// Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

// Left view of following tree is 1 2 4 8.

//           1
//        /     \
//      2        3
//    /     \    /    \
//   4     5   6    7
//    \
//      8   

// Left view of following tree is 1 2 4 8.

void solve(Node*root,int level,vector<int>&ans){
    if(root==NULL) return;
    //main condition u will understand when u make a dry and run on copy
    if(ans.size()==level){
        ans.push_back(root->data);
    }
    // else make a call by increasing the level
    solve(root->left,level+1,ans);
    solve(root->right,level+1,ans);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   vector<int>ans;
   int level=0;
   solve(root,level,ans);
   return ans;
}