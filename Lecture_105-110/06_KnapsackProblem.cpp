/*
We are given N items where each item has some weight and 
profit associated with it. We are also given a bag with 
capacity W, [i.e., the bag can hold at most W weight in it]. 
The target is to put the items into the bag such that the 
sum of profits associated with them is the maximum possible. 
Input: N = 3, W = 4, profit[] = {1, 2, 3}, weight[] = {4, 5, 1}
Output: 3
*/

// 1.Recursive
#include <bits/stdc++.h> 

int solve(vector<int> weight, vector<int> val, int n, int w,vector<vector<int>>&dp){
	if(n<0 && w>=0) return 0; 
	if(n<0 && w<0) return INT_MIN;
	if(w<0) return INT_MIN;
	if(w==0) return 0;
	
	if(dp[n][w]!=-1) return dp[n][w];
	int inc=val[n]+solve(weight,val,n-1,w-weight[n],dp);
	int exc=solve(weight,val,n-1,w,dp);
	return dp[n][w]=max(inc,exc);

}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	int ans=solve(weight,value,n-1,maxWeight,dp);
	if(ans<0) return 0;
	else return ans;
}



// 2.Tabulation
#include <bits/stdc++.h> 

int solve(vector<int> weight, vector<int> val, int n, int capacity){
		vector<vector<int>>dp(n,vector<int>(capacity+1,0));
		// base case
		for(int w=weight[0];w<=capacity;w++){
			if(weight[0]<=capacity) dp[0][w]=val[0];
			else dp[0][w]=0;
		}
        // calculating 
		for(int index=1;index<n;index++){
			for(int w=0;w<=capacity;w++){
				int include=0;
				if(weight[index]<=w){
					include=val[index]+dp[index-1][w-weight[index]];
				}
				int exclude=0+dp[index-1][w];
				dp[index][w]=max(include,exclude);
			}
		}
		return dp[n-1][capacity];
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	int ans=solve(weight,value,n,maxWeight);
	if(ans<0) return 0;
	else return ans;
}