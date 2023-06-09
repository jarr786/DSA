/* 
Question:
Given an array arr[] of positive numbers, The task 
is to find the maximum sum of a subsequence such that 
no 2 numbers in the sequence should be adjacent in the array.

Examples: 
Input: arr[] = {5, 5, 10, 100, 10, 5}
Output: 110
*/
// 1. recursive and memoization

#include <bits/stdc++.h> 

int solve(vector<int> &nums,int i,vector<int>&dp){
    if(i<0){
        return 0;
    }
    if(i==0) return nums[i];
    if(dp[i]!=-1) return dp[i];
    //including
    int a=solve(nums,i-2,dp)+nums[i];
    // excluding
    int b=solve(nums,i-1,dp);

    dp[i]=max(a,b);
    return dp[i];
}

int maximumNonAdjacentSum(vector<int> &nums){
    // vector<int>ans;
    int n=nums.size();
    vector<int>dp(n+1,-1);
    return solve(nums,n-1,dp);
}




// 2. tabulation method function
int solve(vector<int> &nums){
    int n=nums.size();
    vector<int>dp(n,0);
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for(int i=2;i<n;i++){
        int include=nums[i]+dp[i-2];
        int exclude=0+dp[i-1];
        dp[i]=max(include,exclude);
    }
    return dp[n-1];
}

// 2. tabulation +space optimization method function
int solve(vector<int> &nums){
    int n=nums.size();
    int dp1=nums[0];
    int dp2=max(dp1,nums[1]);
    int dp3;
    for(int i=2;i<n;i++){
        int include=nums[i]+dp1;
        int exclude=0+dp2;
        dp3=max(include,exclude);
        dp1=dp2;
        dp2=dp3;
    }
    return dp2;
}