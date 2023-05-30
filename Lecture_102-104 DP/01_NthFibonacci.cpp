#include<bits/stdc++.h>
using namespace std;

// top down approach

int fib(int n,vector<int>&dp){
        //base case given in question
        if(n<=2) return 1;

        // step.2
        if(dp[n]!=-1) return dp[n];

        dp[n]=fib(n-1,dp)+fib(n-2,dp);

        return dp[n];
}
int main()
{
        int n;
        cin>>n;
        // step.1
         vector<int>dp(n+1,-1);
         cout<<fib(n,dp)<<endl;
         
         return 0;
}


//tabular approach

#include<bits/stdc++.h>
using namespace std;

int main()
{
         int n;
         cin>>n;
        //  step 1
         vector<int>dp(n+1,0);
        //  step 2
        dp[1]=1;
        dp[2]=1;
        // step
        for(int i=3;i<=n;i++){
                dp[i]=dp[i-1]+dp[i-2];
        }
        cout<<dp[n]<<endl;
         
}

//space optimization

#include<bits/stdc++.h>
using namespace std;

int main()
{
         int n;
         cin>>n;
        //  step 1
        int dp1=1;
        int dp2=1;
        int dp;
        //  step 2
        for(int i=3;i<=n;i++){
                dp=dp1+dp2;
                dp1=dp2;
                dp2=dp;
        }
        cout<<dp2<<endl;
        return 0;
}