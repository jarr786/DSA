/*
Given a number N. Find the minimum number of 
squares of any number that sums to N. For Example: 
If N = 100 , N can be expressed as (10*10) and also as 
(5*5 + 5*5 + 5*5 + 5*5) but the output will be
1 as minimum number of square is 1 , i.e (10*10).

Example 1:

Input: N = 100
Output: 1
Explanation: 10 * 10 = 100
Example 2:

Input: N = 6
Output: 3
Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 68 
*/
// Memoization
class Solution{
    int solve(int n,vector<int>&dp){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n<0) return INT_MAX;
        if(dp[n]!=-1) return dp[n];
        int ans=INT_MAX;
        for(int i=1;i<=sqrt(n);i++){
            ans=min(ans,1+solve(n-(i*i),dp));
        }
        dp[n]=ans;
        return dp[n];
    }
	public:
	int MinSquares(int n)
	{
	    vector<int>dp(n+1,-1);
	    return solve(n,dp);
	}
};




//Tabulation
int solve(int n){
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=n;j++){
                if(i-(j*j)>=0) dp[i]=min(dp[i],1+dp[i-(j*j)]);
            }
        }
        return dp[n];
    }