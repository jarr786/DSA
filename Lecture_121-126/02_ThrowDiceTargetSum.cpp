/*
Dice throw
MediumAccuracy: 36.52%Submissions: 23K+Points: 4
Join the most popular course on DSA. Master 
Skills & Become Employable by enrolling today! 
Given N dice each with M faces, numbered from 1 to M, 
find the number of ways to get sum X. X is the summation 
of values on each face when all the dice are thrown.
 
Example 1:

Input:
M = 6, N = 3, X = 12
Output:
25
Explanation:
There are 25 total ways to get
the Sum 12 using 3 dices with
faces from 1 to 6.
*/

 class Solution {
    long long solve(int d,int f,int sum,vector<vector<long long>>&dp){
        if(sum<0) return 0;
        if(sum==0 && d==0){
            return 1;
        }
        if(sum==0 && d!=0) return 0;
        if(sum!=0 && d==0) return 0;
        
        if(dp[d][sum]!=-1) return dp[d][sum];
        
        long long ans=0;
        for(int i=1;i<=f;i++){
            ans=ans+solve(d-1,f,sum-i,dp);
        }
        return dp[d][sum]=ans;
    }
    
    
    long long solvetab(int dice,int faces,int target){
        vector<vector<long long>>dp(dice+1,vector<long long>(target+1,0));
        dp[0][0]=1;
        
        for(int d=1;d<=dice;d++){
            for(int sum=0;sum<=target;sum++){
                long long ans=0;
                for(int i=1;i<=faces;i++){
                    if(sum-i>=0)
                        ans=ans+dp[d-1][sum-i];
                }
                dp[d][sum]=ans;
            }
        }
        return dp[dice][target];
    }
  public:
    long long noOfWays(int M , int N , int X) {
    vector<vector<long long>>dp(N+1,vector<long long>(X+1,-1));
        // return solve(N,M,X,dp);
        return solvetab(N,M,X);
    }
};