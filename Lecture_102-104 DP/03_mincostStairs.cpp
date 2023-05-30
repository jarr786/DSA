/*
746. Min Cost Climbing Stairs
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.

Example 1:
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost
*/
// 1. Recursive with memoization Method
class Solution {
    int solve(vector<int>& cost,int n,vector<int>&dp){
        // base case
        if(n==0 || n==1) return cost[n];
        // else
        if(dp[n]!=-1) return dp[n];
        dp[n]=min(solve(cost,n-1,dp),solve(cost,n-2,dp))+cost[n];
        return dp[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int ans;
        int n=cost.size();
        // memoization
        vector<int>dp(n+1,-1);
        ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return ans;
    }
};

// 2. Tabulation Method

int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            int indx;
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }
        return min(dp[n-1],dp[n-2]);
    }

// 3.Space complexity
        int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int dp1,dp2,dp;
        dp1=cost[0];
        dp2=cost[1];
        for(int i=2;i<n;i++){
            dp=min(dp1,dp2)+cost[i];
            dp1=dp2;
            dp2=dp;
        }
        return min(dp1,dp2);
    }    
