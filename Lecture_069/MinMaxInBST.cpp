// minimum and maxi in bst
class Solution
{
    int maxBst(Node *root){
        while(root->right!=NULL){
            root=root->right;
        }
        return root->data;
    }
    int minBst(Node *root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root->data;
    }
public:
    int findMax(Node *root)
    {
        return maxBst(root);
    }
    int findMin(Node *root)
    {
        return minBst(root);
    }
};