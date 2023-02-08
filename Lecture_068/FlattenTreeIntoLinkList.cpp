// Input : 
//           1
//         /   \
//        2     5
//       / \     \
//      3   4     6
// Output :
// 1 2 3 4 5 6 
class Solution
{
    public:
    void flatten(Node *root)
    {
        Node*curr=root;
        while(curr!=NULL){
            // if there is left existence
            if(curr->left!=NULL){
                Node*predesor=curr->left;
                while(predesor->right!=NULL){
                    predesor=predesor->right;
                }
                predesor->right=curr->right;
                curr->right=curr->left;
                    curr->left=NULL;
            }
            curr=curr->right;
        }
        
    }
};