/*
Given a binary matrix mat of size n * m, 
find out the maximum size square sub-matrix with all 1s.
Example 1:
Input: n = 2, m = 2
mat = {{1, 1}, 
       {1, 1}}
Output: 2
*/

//Memoization

class Solution{
    int delta=0;
    int solve(int n, int m, vector<vector<int>>&mat,int i,int j,vector<vector<int>>&dp){
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int left=solve(n,m,mat,i,j+1,dp);
        int right=solve(n,m,mat,i+1,j,dp);
        int digonal=solve(n,m,mat,i+1,j+1,dp);
        int ans=min(left,min(right,digonal));
        
        if(mat[i][j]==1){
            delta=max(ans+1,delta);
            dp[i][j]=ans+1;
            return dp[i][j];
        }
        else return dp[i][j]=0;
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        vector<vector<int>>dp(n,vector<int>(m,-1));
        solve(n,m,mat,0,0,dp);
        return delta;
    }
};


// 

int delta=0;
int solveTab(int n, int m, vector<vector<int>>&mat){
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // traversing from down
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int left=dp[i][j+1];
                int right=dp[i+1][j];
                int digonal=dp[i+1][j+1];
                
                int ans=min(left,min(right,digonal));
                // updating delta 
                if(mat[i][j]==1){
                    dp[i][j]=ans+1;
                    delta=max(ans+1,delta);
                }
                else dp[i][j]=0;
            }
        }
        return delta;
    }


    // Tabulation space optimization 
    int solveTab(int n, int m, vector<vector<int>>&mat){
        vector<int>curr(m+1,0);
        vector<int>next(m+1,0);
        // traversing from down
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int left=curr[j+1];
                int right=next[j];
                int digonal=next[j+1];
                
                int ans=min(left,min(right,digonal));
                
                if(mat[i][j]==1){
                    curr[j]=ans+1;
                    delta=max(ans+1,delta);
                }
                else curr[j]=0;
            }
            next=curr;
        }
        return delta;
    }

