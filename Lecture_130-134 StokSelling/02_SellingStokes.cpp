/*
122. Best Time to Buy and Sell Stock II

You are given an integer array prices where 
prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. 
You can only hold at most one share of the stock at any time. 
However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
*/

class Solution {
    //Recursion
    int solve(vector<int>& prices,int i,int buy){
        if(i>=prices.size()) return 0;
        int profit=0;
        if(buy==0){
            int buykaro=profit-prices[i] + solve(prices,i+1,1);
            int notbuy=profit+0 + solve(prices,i+1,0);
            profit= max(buykaro,notbuy);
        }
        else{
            int sellkaro=solve(prices,i+1,0) + profit+prices[i];
            int selnotl=solve(prices,i+1,1) + profit;
            profit= max(sellkaro,selnotl);
        }
        return profit;
    }

    // Memoization
    int solveMemo(vector<int>& prices,int i,int buy,vector<vector<int>>&dp){
        if(i>=prices.size()) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];
        
        int profit=0;
        if(buy==0){
            int buykaro=solveMemo(prices,i+1,1,dp) + profit-prices[i];
            int notbuy=solveMemo(prices,i+1,0,dp) +  0 + profit;
            profit= max(buykaro,notbuy);
        }
        else{
            int sellkaro=solveMemo(prices,i+1,0,dp) + profit+prices[i];
            int selnotl=solveMemo(prices,i+1,1,dp) + profit;
            profit= max(sellkaro,selnotl);
        }
        return dp[i][buy]=profit;
    }


    //Tabulation
    int solvetab(vector<int>& prices){
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy==0){
                    int buykaro=dp[i+1][1] + profit-prices[i];
                    int notbuy=dp[i+1][0] +  0 + profit;
                    profit= max(buykaro,notbuy);
                }
                else{
                    int sellkaro=dp[i+1][0] + profit+prices[i];
                    int selnotl=dp[i+1][1] + profit;
                    profit= max(sellkaro,selnotl);
                }
                dp[i][buy]=profit;
            }
        }
        return dp[0][0];
    }


    //Tabulation space optimization
    int solvetabSO(vector<int>& prices){
        int n=prices.size();
        vector<int>curr(2,0);
        vector<int>next(2,0);
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy==0){
                    int buykaro=next[1] + profit-prices[i];
                    int notbuy=next[0] +  0 + profit;
                    profit= max(buykaro,notbuy);
                }
                else{
                    int sellkaro=next[0] + profit+prices[i];
                    int selnotl=next[1] + profit;
                    profit= max(sellkaro,selnotl);
                }
                curr[buy]=profit;
            }
            next=curr;
        }
        return curr[0];
    }

public:
    int maxProfit(vector<int>& prices){
        int buy=0;
        int profit=0;
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return solve(prices,0,buy);
        // return solveMemo(prices,0,buy,dp);
        // return solvetab(prices);
        return solvetabSO(prices);
    }
};