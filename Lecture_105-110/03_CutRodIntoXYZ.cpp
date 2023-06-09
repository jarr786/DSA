/* 
Given a rod of length L, the task is to cut the rod in such a way 
that the total number of segments of length p, q, and r is maximized.
The segments can only be of length p, q, and r. 
Examples: 
Input: l = 11, p = 2, q = 3, r = 5 
Output: 5 
Explanation: Segments of 2, 2, 2, 2 and 3
*/

// 1 Recursive +memoization
#include<limits.h>
int solve(int n, int x, int y, int z,vector<int>&dp){
	if(n==0) return 0;
	if(n<0) return -2147483647;

	if(dp[n]!=-1) return dp[n];
	int a=1+solve(n-x,x,y,z,dp);
	int b=1+solve(n-y,x,y,z,dp);
	int c=1+solve(n-z,x,y,z,dp);
	return dp[n]=max(a,max(b,c));
}
int cutSegments(int n, int x, int y, int z) {
	vector<int>dp(n+1,-1);
	int ans=solve(n,x,y,z,dp);
	if(ans<0) return 0;
	else return ans;
}



// 2. tabulation +space optimization method function

#include<limits.h>
int solve(int n, int x, int y, int z){
	vector<int>dp(n+1,INT_MIN);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		if(i-x>=0) dp[i]=max(dp[i],1+dp[i-x]);
		if(i-y>=0) dp[i]=max(dp[i],1+dp[i-y]);
		if(i-z>=0) dp[i]=max(dp[i],1+dp[i-z]);
	}
	return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	vector<int>dp(n+1,-1);
	int ans=solve(n,x,y,z);
	if(ans<0) return 0;
	else return ans;
}