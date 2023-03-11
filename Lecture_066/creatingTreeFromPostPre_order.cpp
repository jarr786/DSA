// Qsn
// preorder  = [1,2,4,5,3,6,7]
// postorder = [4,5,2,6,7,3,1]
// making root for 1
// sub-problem for recursive call at left and right of root
    // for left root call
          // preorder  = [2,4,5]
          // postorder = [4,5,2]
    //for right root call
          // preorder  = [3,6,7]
          // postorder = [6,7,3]   

class Solution {
    int getpostindex(vector<int>&postorder,int x){
        int n=postorder.size();
        for(int i=0;i<n;i++){
            if(postorder[i]==x) return i;
        }
        return -1;
    }
    int getpreindex(vector<int>&preorder,int x){
        int n=preorder.size();
        for(int i=0;i<n;i++){
            if(preorder[i]==x){
                // because we are considering till before index
                return i-1;
            } 
        }
        return -1;
    }
    TreeNode*solve(vector<int>& preorder, vector<int>& postorder,int i,int j,int x,int y){
        if(x>y) return NULL;

        TreeNode*root=new TreeNode(preorder[i]);

        if(x==y) return root;

        // processing indexces to send for recursion
        int pree=getpreindex(preorder,postorder[y-1]);   //preorder->upto end
        int pose=getpostindex(postorder,preorder[i+1]);  //postorder->end
        
        root->left=solve(preorder,postorder,i+1,pree,x,pose);
        root->right=solve(preorder,postorder,pree+1,j,pose+1,y-1);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode*ans;
        int n=postorder.size();
        int i=0,j=n-1,x=0,y=n-1;
        ans=solve(preorder,postorder,i,j,x,y);
        return ans;
    }
};