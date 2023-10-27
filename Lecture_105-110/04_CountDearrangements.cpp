/*
A Derangement is a permutation of n elements, such that
 no element appears in its original position. 
For example, a derangement of {0, 1, 2, 3} is {2, 3, 1, 0}.
Given a number n, find the total number of Derangements of a set of n elements.
Examples :
Input: n = 3
Output: 2
For three elements say {0, 1, 2}, there are two 
possible derangements {2, 0, 1} and {1, 2, 0}
*/
#include<vector>
#define MOD 1000000007
long long int solve(int n,vector<long long int>&dp){
    if(n==1) return 0;
    if(n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    dp[n]=(((n-1)%MOD)*((solve(n-1,dp)%MOD)+(solve(n-2,dp)%MOD))%MOD);
    return dp[n];
}
long long int countDerangements(int n) {
    vector<long long int>dp(n+1,-1);
    return solve(n,dp);
}