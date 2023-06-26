/*
Partition Equal Subset Sum
MediumAccuracy: 30.24%Submissions: 168K+Points: 4
Join the most popular course on DSA. Master Skills & 
Become Employable by enrolling today! 
Given an array arr[] of size N, check if it can be 
partitioned into two parts such that the sum of 
elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explanation: This array can never be 
partitioned into two such parts.
*/

class Solution{
    // Recursive solution
    int solve(int arr[],int n,int i,int sum){
        if(sum<0)  return 0;
        if(sum==0) return 1;
        if(i>=n)   return 0;
        int a=solve(arr,n,i+1,sum-arr[i]);
        int b=solve(arr,n,i+1,sum);
        
        return a || b;
    }
    
    // Memoization 
    int solveMemo(int arr[],int n,int i,int sum,vector<vector<int>>&dp){
        if(sum<0)  return 0;
        if(sum==0) return 1;
        if(i>=n)   return 0;
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        int a=solveMemo(arr,n,i+1,sum-arr[i],dp);
        int b=solveMemo(arr,n,i+1,sum,dp);
        
        dp[i][sum]=a || b;
        
        return a || b;
    }
    
    // Tabulation
    
    int solveTab(int arr[],int n,int target){
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        // base case
        for(int k=0;k<=n;k++){
            dp[k][0]=1;
        }
        for(int i=n-1;i>=0;i--){
            for(int sum=0;sum<=target;sum++){
                int a=0,b=0;
                if(sum-arr[i]>=0)
                    a= dp[i+1][sum-arr[i]];
                    
                    b=dp[i+1][sum];
                
                dp[i][sum]=a || b;
            }
        }
        return dp[0][target];
    }
    
    
    // Tabulation Space optimization
    
    int solveTabSO(int arr[],int n,int target){
        // only two rows enought
        vector<int>curr(target+1,0);
        vector<int>next(target+1,0);
        // base case
        curr[0]=1;
        next[0]=1;
        for(int i=n-1;i>=0;i--){
            for(int sum=0;sum<=target;sum++){
                int a=0,b=0;
                if(sum-arr[i]>=0)
                    a= next[sum-arr[i]];
                    
                    b=next[sum];
                
                curr[sum]=a || b;
            }
            next=curr;
        }
        return curr[target];
    }
public:
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum & 1) return 0;
        sum/=2;
        
        vector<vector<int>>dp(N,vector<int>(sum+1,-1));
        
        // return solve(arr,N,0,sum);
        // return solveMemo(arr,N,0,sum,dp);
        // return solveTab(arr,N,sum);
        return solveTabSO(arr,N,sum);
    }
};


/*
    Approach : 
        Is to find sum if sum is odd cant be done into half partition
        else half the sum and search for the half sum is u are able to 
        find then return true else false;
*/
