// Qsn-Minimum number of coins required to 
//make a target sum

//simple recursive solution
#include <bits/stdc++.h> 
int solve(vector<int> &num, int x){
    if(x==0) return 0;
    if(x<0) return INT_MAX;
    int mini=INT_MAX;
    for(int i=0;i<num.size();i++){
        int ans=solve(num,x-num[i]);
        if(ans!=INT_MAX){
            mini=min(mini,ans+1);
        }
    }
    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    int ans=solve(num,x);
    if(ans==INT_MAX) return -1;
    else return ans;
}

//memoization and recursion
#include <bits/stdc++.h> 
int solve(vector<int> &num, int x,vector<int>&dp){
    if(x==0) return 0;
    if(x<0) return INT_MAX;
    int mini=INT_MAX;

    if(dp[x]!=-1) return dp[x];

    for(int i=0;i<num.size();i++){
        int ans=solve(num,x-num[i],dp);
        if(ans!=INT_MAX){
            mini=min(mini,ans+1);
            dp[x]=mini;
        }
    }
    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    vector<int>dp(x+1,-1);
    int ans=solve(num,x,dp);
    if(ans==INT_MAX) return -1;
    else return ans;
}

//tabulation method
#include <bits/stdc++.h> 
int solve(vector<int> &num, int x ){
   vector<int>dp(x+1,INT_MAX);
   dp[0]=0;

   for(int i=0;i<=x;i++){
    //    im trying to solve for every amount figure from 1 to x
    for(int j=0;j<num.size();j++){
        if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX){
            dp[i]=min(dp[i],1+dp[i-num[j]]);
        }
    }
   }
   return dp[x];
}
int minimumElements(vector<int> &num, int x)
{
    int ans=solve(num,x);
    if(ans==INT_MAX) return -1;
    else return ans;
}