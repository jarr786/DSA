       
    /*   Qsn-Flatten BST To A Sorted List
       ****************************************************** */
void inorder(TreeNode<int>*root,vector<int>&v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int>v;
    inorder(root,v);

    TreeNode<int>*curr=new TreeNode<int>(v[0]);
    TreeNode<int>*head=curr;
    
    for(int i=1;i<v.size();i++){
        TreeNode<int>*temp=new TreeNode<int>(v[i]);
        curr->right=temp;
        curr->left=NULL;
        curr=temp;
    }
    curr->left=NULL;
    curr->right=NULL;
    return head;
}