/*
Input: 
Tree = 
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
K = 5                    
Output: 8
Explanation:
The following paths sum to K.  
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5 */

class Solution{
    void solve(Node*root,int k,int&cnt,vector<int>v){
        //this s base case
        if(root==NULL) return;
        
        v.push_back(root->data);
        
        solve(root->left,k,cnt,v);
        solve(root->right,k,cnt,v);
        
        //check for the k sum
        int sum=0;
        for(int i=v.size()-1;i>=0;i--){
            sum+=v[i];
            if(sum==k) cnt++;
        }
    }
  public:
    int sumK(Node *root,int k)
    {
        int cnt=0;
        vector<int>v;
        solve(root,k,cnt,v);
        return cnt;
    }
};