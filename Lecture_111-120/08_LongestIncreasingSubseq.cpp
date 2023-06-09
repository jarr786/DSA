/*
Given an array of integers, find the length of the 
longest (strictly) increasing subsequence from the given array.

Example 1:

Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6
*/

class Solution
{
    int solve(int n, int arr[],int curr,int prev,vector<vector<int>>&dp){
        if(curr==n) return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        // including 
        int inc=0;
        if(prev==-1 || arr[curr]>arr[prev]) inc= 1+solve(n,arr,curr+1,curr,dp);
        // excluding
        int exc= solve(n,arr,curr+1,prev,dp);
        return dp[curr][prev+1]=max(inc,exc);
    }
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int prev=-1;  // taking any prev value
        return solve(n,arr,0,prev,dp);
    }
};

//Tabulation
int solvetab(int n, int arr[]){
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                // including 
                int inc=0;
                if(prev==-1 || arr[curr]>arr[prev]) inc= 1+dp[curr+1][curr+1];
                // excluding
                int exc= dp[curr+1][prev+1];
                dp[curr][prev+1]=max(inc,exc);
            }
        }
        return dp[0][0];
    }


//Tabulation SO
int solvetab(int n, int arr[]){
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                // including 
                int inc=0;
                if(prev==-1 || arr[curr]>arr[prev]) inc= 1+nextRow[curr+1];
                // excluding
                int exc= nextRow[prev+1];
                currRow[prev+1]=max(inc,exc);
            }
            nextRow=currRow;
        }
        return currRow[0];
    }


//Optimal Solution
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int nums[])
    {
        vector<int>ans;
        ans.push_back(nums[0]);
        
        for(int j=1;j<n;j++){
            int i=nums[j];
            
            if(i>ans.back()) ans.push_back(i);
            else{
                int index=lower_bound(ans.begin(),ans.end(),i)-ans.begin();
                ans[index]=i;
            }
            
        }
        return ans.size();
    }
};