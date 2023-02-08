// Input:
// k=1 
// node=3
//       1
//     /   \
//     2     3

// Output:
// 1
// Explanation:
// K=1 and node=3 ,Kth ancestor of node 3 is 1.
Node* solve(Node*root,int&k,int node){
    if(root==NULL) return NULL;
    
    if(root->data==node) return root;
    
    Node*left=solve(root->left,k,node);
    Node*right=solve(root->right,k,node);
    
    if(left!=NULL && right==NULL){
        k--; 
        if(k==0){
            // k=INT_MAX;
        return root;
        }
        return left;
    }
    if(left==NULL && right!=NULL){
         k--; 
        if(k==0){
            // k=INT_MAX;
        return root;
        }
        return right;
    }
     return NULL;
}
// your task is to complete this function
int kthAncestor(Node *root, int k, int node)
{
    Node*ans=solve(root,k,node);
    if(ans==NULL || ans->data==node) return -1;
    return ans->data;
}