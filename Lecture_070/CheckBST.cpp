 //check if a tree is bst
 class solution{
 public:
    bool solve(Node*root,int min,int max){
        if(root==NULL){
            return true;
        }
        if(root->data>min && root->data<max){
            
            bool left=solve(root->left,min,root->data);
            bool right=solve(root->right,root->data,max);
            
            return left && right;
        }
        else return false;
    }
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        return solve(root,INT_MIN,INT_MAX);
    }
};

// another aproach
//  traverse the tree and by inorder method and store it into a vector
//as we know that inorder of a bst is sorted 
//chek whether the inorder is sorted return true if ,else false