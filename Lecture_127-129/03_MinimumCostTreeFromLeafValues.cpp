/*
1130. Minimum Cost Tree From Leaf Values
 
Given an array arr of positive integers, 
consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in 
an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of 
the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the 
smallest possible sum of the values of each non-leaf node. 
It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.

Example 1:

Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
*/

class Solution {
    // range based maximum
    map<pair<int,int>,int>map;

    // Recursion
    int Solve(vector<int>& arr,int start,int end){
        if(start==end) return 0;
        int ans=INT_MAX;
        for(int i=start;i<end;i++){
            int x=map[{start,i}]*map[{i+1,end}]+Solve(arr,start,i)+Solve(arr,i+1,end);
            ans=min(ans,x);
        }
        return ans;
    }


    // Memoization
    int Memoiz(vector<int>& arr,int start,int end,vector<vector<int>>&dp){
        if(start==end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int ans=INT_MAX;
        for(int i=start;i<end;i++){
            int x=map[{start,i}]*map[{i+1,end}]+Memoiz(arr,start,i,dp)+Memoiz(arr,i+1,end,dp);
            ans=min(ans,x);
        }
        return dp[start][end]=ans;
    }


    //Tabulation
    int Tabulation(vector<int>& arr){
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int start=n-1;start>=0;start--){
            for(int end=0;end>n;end++){
                if(start==end) continue;
                else{
                    int ans=INT_MAX;
                    for(int i=start;i<end;i++){
                        int x=map[{start,i}]*map[{i+1,end}]+dp[start][i]+dp[i+1][end];
                        ans=min(ans,x);
                    }
                    dp[start][end]=ans;
                }
            }
        }
        return dp[0][n-1];
    }
public:
    int mctFromLeafValues(vector<int>& arr){
        int n=arr.size();
        for(int i=0;i<n;i++){
            map[{i,i}]=arr[i];
            int maxi=arr[i];
            for(int j=i+1;j<n;j++){
                maxi=max(maxi,arr[j]);
                map[{i,j}]=maxi;
            }
        }

        vector<vector<int>>dp(n,vector<int>(n,-1));
        // return Solve(arr,0,n-1);
        return Memoiz(arr,0,n-1,dp);
    }
};