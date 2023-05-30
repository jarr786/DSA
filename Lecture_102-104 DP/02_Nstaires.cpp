// Qsn-cdnjs  Count Ways To Reach The N-th Stairs

#include <bits/stdc++.h> 
#define mod 1000000007
int count(int nStairs,vector<int>&dp) {
    //base case
    if (nStairs==0) return 1;
    if (nStairs==1) return 1;

    if(dp[nStairs]!=-1) return dp[nStairs]%mod;    
    //recursive relation wiht memoization
    dp[nStairs]=count( nStairs-1,dp)+count( nStairs-2,dp);
    return dp[nStairs]%mod;
}
int countDistinctWays(int nStairs){
    vector<int>dp(nStairs+1,-1);
    return count(nStairs,dp);
}