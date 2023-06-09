/*
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed. All houses at this place are arranged in a circle.
you can rob only non adjacent houses
return the maximum amount of money you can rob tonight without alerting the police.
Input: nums = [2,3,2]
Output: 3
*/
long long int solve(vector<int>& nums,int n,vector<long long int>&dp,int size){
        if(n>=size){
            return 0;
        }
        if(dp[n]!=-1) return dp[n];

        long long int include=nums[n]+solve(nums,n+2,dp,size);
        long long int exclude=0+solve(nums,n+1,dp,size);

        return dp[n]=max(include,exclude);
    }


long long int houseRobber(vector<int>&a) {
    // code
    int x=a.size();
        if(x==1) return a[0];
    vector<long long int>dp(a.size()+1,-1);
    // including first excluding last
    long long int ans1=solve(a,0,dp,x-1);
    // reseting dp vector to -1
    for(int i=0;i<x+1;i++) dp[i]=-1;
    // including last excluding first;
    long long int ans2=solve(a,1,dp,x);

    return max(ans1,ans2);
}

