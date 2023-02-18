            // Return the Kth smallest element in the given BST

class Solution {
    int solve(Node*root,int k,int &i){
        if(root==NULL){
            return -1;
        }
        int left=solve(root->left,k,i);
        
        if(left!=-1) return left;
        
        i++;
        
        if(i==k) return root->data;
        
        return solve(root->right,k,i);
    }
  public:
    
    int KthSmallestElement(Node *root, int k) {
        int i=0;
        int ans=solve(root,k,i);
        return ans;
    }
};

//if kth largest will be n-k+1 smallest.