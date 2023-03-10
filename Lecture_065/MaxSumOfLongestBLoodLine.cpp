/*
Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Example 1:

Input: 
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output: 13
Explanation:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3 
      /
     6

The highlighted nodes (4, 2, 1, 6) above are 
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13 */


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
