// Input:
//      2
//   /    \
//  1       3
// n1 = 1, n2 = 3
// Output: 2


//Function to find the lowest common ancestor in a BST. 
Node* LCA(Node *root, int n1, int n2)
{
   if(root==NULL) return NULL;
   if(root->data==n1 || root->data==n2){
       return root;
   }
   Node*left=LCA(root->left,n1,n2);
   Node*right=LCA(root->right,n1,n2);
   if(left!=NULL && right!=NULL){
       return root;
   }
   else if(left==NULL && right!=NULL){
       return right;
   }
   else if(left!=NULL && right==NULL){
       return left;
   }
   else{
      return NULL;
   }
}
