/*
Return the smallest possible total score that 
you can achieve with some triangulation of the polygon.
Input: values = [3,7,4,5]
Output: 144
Explanation: There are two triangulations, 
with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
The minimum score is 144.
*/

//Recursion
class Solution {
    int solve(vector<int>& values,int i,int j){
        if(i+1==j) return 0;
        int delta=INT_MAX;
        for(int f=i+1;f<j;f++){
            int ans=(values[f]*values[i]*values[j])+solve(values,i,f)+solve(values,f,j);
            cout<<ans<<endl;
            delta=min(delta,ans);
        }
        return delta;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(values,0,values.size()-1);
    }
};

// Memoization
    int solve(vector<int>& values,int i,int j,vector<vector<int>>&dp){
        if(i+1==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int delta=INT_MAX;
        for(int f=i+1;f<j;f++){
            int ans=(values[f]*values[i]*values[j])+solve(values,i,f,dp)+solve(values,f,j,dp);
            delta=min(delta,ans);
        }
        dp[i][j]=delta;
        return dp[i][j];
    }
 


//tabulation
    int solvetab(vector<int>& values){
        int n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int i=n-1;i>=0;i--){
            for(int j=i+2;j<n;j++){
                int delta=INT_MAX;
                for(int f=i+1;f<j;f++){
                    int ans=(values[f]*values[i]*values[j])+ dp[i][f]+dp[f][j];
                    delta=min(delta,ans);
                }
                dp[i][j]=delta;
            }
        }
        return dp[0][n-1];
    }
