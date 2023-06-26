/*
123. Best Time to Buy and Sell Stock III

Find the maximum profit you can achieve. 

****You may complete at most two transactions.

Note: You may not engage in multiple transactions 
simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
*/


//3-D dp


class Solution {
    //Recursion
    int solve(vector<int>& prices,int i,int buy,int limit){
        if(i>=prices.size()) return 0;
        if(limit==0) return 0;

        int profit=0;
        if(buy==0){
            int buykaro=profit-prices[i] + solve(prices,i+1,1,limit);
            int notbuy=profit+0 + solve(prices,i+1,0,limit);
            profit= max(buykaro,notbuy);
        }
        else{
            int sellkaro=solve(prices,i+1,0,limit-1) + profit+prices[i];
            int selnotl=solve(prices,i+1,1,limit) + profit;
            profit= max(sellkaro,selnotl);
        }
        return profit;
    }

    // Memoization
    int solveMemo(vector<int>& prices,int i,int buy,vector<vector<vector<int>>>&dp,int limit){
        if(i>=prices.size()) return 0;
        if(limit==0) return 0;

        if(dp[i][buy][limit]!=-1) return dp[i][buy][limit];
        
        int profit=0;
        if(buy==0){
            int buykaro=solveMemo(prices,i+1,1,dp,limit) + profit-prices[i];
            int notbuy=solveMemo(prices,i+1,0,dp,limit) +  0 + profit;
            profit= max(buykaro,notbuy);
        }
        else{
            int sellkaro=solveMemo(prices,i+1,0,dp,limit-1) + profit+prices[i];
            int selnotl=solveMemo(prices,i+1,1,dp,limit) + profit;
            profit= max(sellkaro,selnotl);
        }
        return dp[i][buy][limit]=profit;
    }


    //Tabulation
    int solvetab(vector<int>& prices){
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=2;limit++){
                    int profit=0;
                    if(buy==0){
                        int buykaro=dp[i+1][1][limit] -prices[i];
                        int notbuy=dp[i+1][0][limit] +  0 ;
                        profit= max(buykaro,notbuy);
                    }
                    else{
                        int sellkaro=dp[i+1][0][limit-1] +prices[i];
                        int selnotl=dp[i+1][1][limit] + 0;
                        profit= max(sellkaro,selnotl);
                    }
                    dp[i][buy][limit]=profit;
                }
            }
        }
        return dp[0][0][2];
    }


    //Tabulation space optimization
    int solvetabSO(vector<int>& prices){
        int n=prices.size();
        vector<vector<int>>curr(2,vector<int>(3,0));
        vector<vector<int>>next(2,vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=2;limit++){
                    int profit=0;
                    if(buy==0){
                        int buykaro=next[1][limit] -prices[i];
                        int notbuy=next[0][limit] +  0 ;
                        profit= max(buykaro,notbuy);
                    }
                    else{
                        int sellkaro=next[0][limit-1] +prices[i];
                        int selnotl=next[1][limit] + 0;
                        profit= max(sellkaro,selnotl);
                    }
                    curr[buy][limit]=profit;
                }
            }
            next=curr;
        }
        return curr[0][2];
         
    }

public:
    int maxProfit(vector<int>& prices){
        int buy=0;
        int profit=0;
        int limit=2;
        int n=prices.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // return solve(prices,0,buy,limit);
        // return solveMemo(prices,0,buy,dp,limit);
        // return solvetab(prices);
        return solvetabSO(prices);
    }
};