/*
Longest Common Subsequence
Given two sequences, find the length of longest subsequence 
present in both of them. Both the strings are of uppercase.

Example 1:

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.
Example 2:

Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2
Explanation: LCS of "ABC" and "AC" is
"AC" of length 2.
*/

class Solution
{
    int solve(string a,string b,int i,int j){
        if(i>=a.length() || j>=b.length()){
            return 0;
        }
        if(a[i]==b[j]) return 1+solve(a,b,i+1,j+1);
        else return max(solve(a,b,i+1,j),solve(a,b,i,j+1));
    }
    
    //Memoization
    
    int solvememo(string a,string b,int i,int j,vector<vector<int>>&dp){
        if(i>=a.length() || j>=b.length()){
            return 0;
        }
        if(dp[i][j]!=1) return dp[i][j];
        
        int ans=0;
        
        if(a[i]==b[j]) ans= 1+solvememo(a,b,i+1,j+1,dp);
        else ans=max(solvememo(a,b,i+1,j,dp),solvememo(a,b,i,j+1,dp));
        
        return dp[i][j]=ans;
    }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2){
        vector<vector<int>>dp(x,vector<int>(y,1));
        return solvememo(s1,s2,0,0,dp);
    }
};
