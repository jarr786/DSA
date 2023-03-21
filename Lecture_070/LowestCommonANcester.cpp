// 235. Lowest Common Ancestor of a Binary Search Tree
        //  Recursive approach
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL) return NULL;
     if(root->val>p->val && root->val>q->val){
         return lowestCommonAncestor(root->left,p,q);
     }
     if(root->val<p->val && root->val<q->val){
         return lowestCommonAncestor(root->right,p,q);
     }
     return root;
    }


        //Iteravtive approach

    // TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode*p,TreeNode* q) {
    // if(root==NULL) return NULL;
    // while(root!=NULL){
    //     if(root->val>p->val && root->val>q->val){
    //         root=root->left;
    //     }
    //     else if(root->val<p->val && root->val<q->val){
    //         root=root->right;
    //     }
    //     else return root;
    // }
    // return NULL;
    // }
};