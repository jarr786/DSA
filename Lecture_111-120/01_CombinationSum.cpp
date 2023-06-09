/*
Given an array of positive integers arr[] and an integer x, 
The task is to find all unique combinations in arr[] where 
the sum is equal to x. 
Input: arr[] = 2, 4, 6, 8, x = 8
Output: 5
[2, 2, 2, 2]
[2, 2, 4]
[2, 6]
[4, 4]
[8]
*/

// Memoization

#include <bits/stdc++.h> 
int solve(int n,vector<int>&v,vector<int>&dp){
	if(n==0) return 1;
	if(n<0) return 0;
	if(dp[n]!=-1) return dp[n];
	int ans=0;
	for(int i=0;i<v.size();i++) ans+=solve(n-v[i],v,dp);
	dp[n]=ans;
	return dp[n];
}

// Tabulation

int solveTab(vector<int> &num, int tar){
	vector<int>dp(tar+1,0);
	dp[0]=1;

    // travering for all targets
	for(int i=0;i<=tar;i++){
		// traversing on num vector 
		for(int j=0;i<num.size();i++){
			if(i-num[j]>=0)  dp[i]+=dp[i-num[j]];
		}
	}
	return dp[tar];
}


int findWays(vector<int> &num, int tar)
{
	int n=num.size();
	vector<int>dp(tar+1,-1);
    return solve(tar,num,dp);
}