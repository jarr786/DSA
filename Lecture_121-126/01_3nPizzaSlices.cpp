/*
1388. Pizza With 3n Slices
 
There is a pizza with 3n slices of varying size, you and 
your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Given an integer array slices that represent the sizes of the pizza 
slices in a clockwise direction, return the maximum possible sum of slice 
sizes that you can pick.

Example 1:

Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.
*/

class Solution {
    int solve(vector<int>& slices,int start,int n,int end){
        if(n==0) return 0;
        if(start>=end){
            return 0;
        }
        // including 
        int inc=slices[start]+solve(slices,start+2,n-1,end);
        // excluding
        int exc=solve(slices,start+1,n,end);

        return max(inc,exc);
    }



    int solveMemo(vector<int>& slices,int start,int n,int end,vector<vector<int>>&dp){
        if(n==0) return 0;
        if(start>=end){
            return 0;
        }
        if(dp[start][n]!=-1) return dp[start][n];
        int inc=slices[start]+solveMemo(slices,start+2,n-1,end,dp);
        int exc=solveMemo(slices,start+1,n,end,dp);
        return dp[start][n]=max(inc,exc);
    }



    int solvetab(vector<int>& slices){
        int n=slices.size();
        vector<vector<int>>dp(n+2,vector<int>(n/3+2,0));
        for(int start=n-2;start>=0;start--){
            for(int j=1;j<=n/3;j++){
                int inc=slices[start]+dp[start+2][j-1];
                int exc=dp[start+1][j];
                dp[start][j]=max(inc,exc);
            }
        }
        int case1=dp[0][n/3];

        vector<vector<int>>dp2(n+2,vector<int>(n/3+2,0));
        for(int start=n-1;start>=1;start--){
            for(int j=1;j<=n/3;j++){
                int inc=slices[start]+dp2[start+2][j-1];
                int exc=dp2[start+1][j];
                dp2[start][j]=max(inc,exc);
            }
        }
        int case2=dp2[1][n/3];

        return max(case1,case2);
    }


    
    int solvetabSO(vector<int>& slices){
        int n=slices.size();
        vector<int>curr(n/3+2,0);
        vector<int>prev1(n/3+2,0);
        vector<int>prev2(n/3+2,0);
        for(int start=n-2;start>=0;start--){
            for(int j=1;j<=n/3;j++){
                int inc=slices[start]+prev2[j-1];
                int exc=prev1[j];
                curr[j]=max(inc,exc);
            }
            prev2=prev1;
            prev1=curr;
        }
        int case1=curr[n/3];

        vector<int>curr2(n/3+2,0);
        vector<int>prev11(n/3+2,0);
        vector<int>prev22(n/3+2,0);
        for(int start=n-1;start>=1;start--){
            for(int j=1;j<=n/3;j++){
                int inc=slices[start]+prev22[j-1];
                int exc=prev11[j];
                curr2[j]=max(inc,exc);
            }
            prev22=prev11;
            prev11=curr2;
        }
        int case2=curr2[n/3];

        return max(case1,case2);
    }

    
public:
    int maxSizeSlices(vector<int>& slices){
        int size=slices.size(); 
        // n is the no of pizza you have to pick
        int n=size/3; 

        // vector<vector<int>>dp(size,vector<int>(n+1,-1));
        // int case1=solveMemo(slices,0,n,size-1,dp);

        // vector<vector<int>>dp2(size,vector<int>(n+1,-1));
        // int case2=solveMemo(slices,1,n,size,dp2);

        // return max(case1,case2);

        // return solvetab(slices);
        return solvetabSO(slices);


        /*
           idea is make two cases if you are taking index zero pizza than you
           cant take last pizza 
           and if last one is taken than u cant take first one pizza
        */
    }
};