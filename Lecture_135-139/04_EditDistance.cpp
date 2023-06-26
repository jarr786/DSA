/*
72. Edit Distance

Given two strings word1 and word2, return the minimum 
number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse > rorse (replace 'h' with 'r')
rorse > rose (remove 'r')
rose > ros (remove 'e')
*/

class Solution {
    int solve(string a, string b,int i,int j){
        if(i>=a.length()) return b.length()j;
        if(j>=b.length()) return a.length()i;

        if(a[i]==b[j]) return solve(a,b,i+1,j+1);

        else{
            int ins=1+solve(a,b,i,j+1);
            int dlt=1+solve(a,b,i+1,j);
            int rep=1+solve(a,b,i+1,j+1);
            return min(ins,min(dlt,rep));
        }
    }

    //Memoization
    int Memoization(string a, string b,int i,int j,vector<vector<int>>&dp){
        if(i>=a.length()) return b.length()j;
        if(j>=b.length()) return a.length()i;

        if(dp[i][j]!=1) return dp[i][j];
        int ans=0;
        if(a[i]==b[j]) return Memoization(a,b,i+1,j+1,dp);
        else{
            int ins=1+Memoization(a,b,i,j+1,dp);
            int dlt=1+Memoization(a,b,i+1,j,dp);
            int rep=1+Memoization(a,b,i+1,j+1,dp);
            ans=min(ins,min(dlt,rep));
        }
        return dp[i][j]=ans;
    }
    
public:
    int minDistance(string word1, string word2) {
        // return solve(word1,word2,0,0);
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n,vector<int>(m,1));
        return Memoization(word1,word2,0,0,dp);
    }
};