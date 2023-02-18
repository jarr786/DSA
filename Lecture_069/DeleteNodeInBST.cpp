int minBst(Node *root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root->data;
    }
// Function to delete a node from BST.
Node *deleteNode(Node *root, int X) {
    //if root is NULL
    if(root==NULL) return root;
    
    if(root->data==X){
    //if node which we r going to delete has only one child
    //node have no child
    if(root->left==NULL && root->right==NULL){
        delete root;
        return NULL;
    }
    // if it is left child
    if(root->left!=NULL && root->right==NULL){
        Node*temp=root->left;
        delete root;
        return temp;
    }
    // if it is rightt child
    if(root->left==NULL && root->right!=NULL){
        Node*temp=root->right;
        delete root;
        return temp;
    }
    //if both child exists of node to be deleted
    if(root->left!=NULL && root->right!=NULL){
        int mini=minBst(root->right);
        root->data=mini;
        root->right=deleteNode(root->right,mini);
        return root;
    }
    }
    else if(root->data>X){
        root->left= deleteNode(root->left,X);
        return root;
    }
    else if (root->data<X){
        root->right= deleteNode(root->right,X);
        return root;
    }
}