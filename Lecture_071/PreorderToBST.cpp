
// Qsn-Preorder to BST

class Solution{
public:
Node* solve(int pre[],int &size,int mini,int maxi,int &i){
    
    if(i>=size) return NULL;
    if(pre[i]>maxi || pre[i]<mini) return NULL;
    
    // //else we will create a node
    Node* root=newNode(pre[i]);
        i++;
    root->left=solve(pre,size,mini,root->data,i);
    root->right=solve(pre,size,root->data,maxi,i);
    
    return root;
}
    //Function that constructs BST from its preorder traversal.
    Node* post_order(int pre[], int size)
    {
        int mini=INT_MIN;
        int maxi=INT_MAX;
        int i=0;
        return solve(pre,size,mini,maxi,i );
    }
};