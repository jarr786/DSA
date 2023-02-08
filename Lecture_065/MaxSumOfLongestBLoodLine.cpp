class Solution
{
public:
    void solve(Node*root,pair<int,int>&ans,pair<int,int>temp){
        if(root==NULL){
            
            // updating ans if condition is full fill
            if(temp.first>ans.first){
               ans=temp;
            }
            else if(temp.first==ans.first){
                ans.second=max(ans.second,temp.second);
            }
            return;
        }
        //otherwise add corrent node
        temp.second+=root->data;
        temp.first+=1;
        //make calls
        solve(root->left,ans,temp);
        solve(root->right,ans,temp);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        // pair<number of nodes,sum>
        pair<int,int>ans={0,0};
        // maintaing a temprary ans
        pair<int,int>temp={0,0};
        solve(root,ans,temp);
        return ans.second;
    }
};