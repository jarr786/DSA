 
//  Qsn-Find a pair with given target in BST

class Solution{
    void inorder(struct Node *root,vector<int>&v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
         if(root->left==NULL && root->right==NULL) return 0;  //single node case
         vector<int>v;
         inorder(root,v);
         int s=0;
         int e=v.size()-1;
         while(s<e){
            if(v[s]+v[e]==target) return 1;
            if(v[s]+v[e]>target) e--;
            if(v[s]+v[e]<target) s++;
         }
         return 0;
    }
};