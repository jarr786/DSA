// This traversal is of inorder type 
// with o(n) and o(1) complexity
class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        Node*curr=root;
        vector<int>ans;
        //run loop till curr become null
        while(curr!=NULL){
            // if there is no left part 
            if(curr->left==NULL){
                ans.push_back(curr->data);
                curr=curr->right;
            }
            //if there is left part exist
            else{
                Node*predesor=curr->left;
                while(predesor->right!=NULL && predesor->right != curr){
                    predesor=predesor->right;
                }
                //predesor null h to not null kar de otherwise point to curr
                if(predesor->right==NULL){
                    predesor->right=curr;
                    curr=curr->left;
                }
                else{
                    predesor->right=NULL;
                    ans.push_back(curr->data);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};