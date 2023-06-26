/*
714. Best Time to Buy and Sell Stock with Transaction Fee
 
You are given an array prices where prices[i] is the price of a 
given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many 
transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., 
you must sell the stock before you buy again).

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
*/

class Solution {
    // Memoization
    int solveMemo(vector<int>& prices,int i,int buy,int fee,vector<vector<int>>&dp){
        if(i>=prices.size()) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];
        
        int profit=0;
        if(buy==0){
            int buykaro=solveMemo(prices,i+1,1,fee,dp) + profit-prices[i];
            int notbuy=solveMemo(prices,i+1,0,fee,dp) +  0 + profit;
            profit= max(buykaro,notbuy);
        }
        else{
            int sellkaro=solveMemo(prices,i+1,0,fee,dp) + profit+prices[i]-fee;
            int selnotl=solveMemo(prices,i+1,1,fee,dp) + profit;
            profit= max(sellkaro,selnotl);
        }
        return dp[i][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy=0;
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solveMemo(prices,0,0,fee,dp);
    }
};