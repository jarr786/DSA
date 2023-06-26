/*
Longest Palindromic Subsequence

Given a String, find the longest palindromic subsequence.

Example 1:

Input:
S = "bbabcbcab"
Output: 7
Explanation: Subsequence "babcbab" is the
longest subsequence which is also a palindrome.
Example 2:

Input: 
S = "abcd"
Output: 1
Explanation: "a", "b", "c" and "d" are
palindromic and all have a length 1.
*/

class Solution{
    int solve(string s,string p,int i,int j,vector<vector<int>>&dp){
        if(i==0 || j==0) return 0;
        if(dp[i][j]!=1) return dp[i][j];

        if(s[i1]==p[j1]) return dp[i][j]=1 + solve(s,p,i1,j1,dp);
        else return dp[i][j]=max(solve(s,p,i,j1,dp),solve(s,p,i1,j,dp));
    }
  public:
    int longestPalinSubseq(string s) {
        //code here
        int n=s.length();
        string p=s;
        reverse(p.begin(),p.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,1));
        return solve(s,p,n,n,dp);
    }
};