/*

*/

class Solution
{
    long d=1000000007;  //for modulus
    
    
    // Recursive solution Dp
    int solve(int n,vector<long long>&dp){
        //basecase
        if(n<=1) return 1;
        
        if(dp[n]!=-1) return dp[n];
        
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans+=((solve(i-1,dp)%d) * (solve(n-i,dp)%d))%d;
        }
        return dp[n]=ans%d;
    }
    
    
    int tabulation(int m){
        vector<long long>dp(m+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int n=2;n<=m;n++){
            long long ans=0;
            for(int i=1;i<=n;i++){
                ans+=((dp[i-1]%d) * (dp[n-i]%d))%d;
            }
            dp[n]=ans%d;
        }
        return dp[m];
    }
    public:
    int numTrees(int N) 
    {
        vector<long long>dp(N+1,-1);
        // return solve(N,dp);
        return tabulation(n);
    }
};