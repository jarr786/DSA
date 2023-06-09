/*
Ninja's Trip
calculate minimum cost to travel for the days in array 
by purchasing tickets of 1 day 7 day and 30 days
Example:
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.
*/

// Recursive soln 

int solve(int n, vector<int>&days, vector<int>&cost,int index){
    if(index>=n) return 0;
    //pass for 1 day
    int op1=cost[0]+solve(n,days,cost,index+1);
    
    // pass for 7 days
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);
    int op2=cost[1]+solve(n,days,cost,i);

    // pass for 30 days
    for(i=index;i<n && days[i]<days[index]+30;i++);
    int op3=cost[2]+solve(n,days,cost,i);

    return min(op1,min(op2,op3));
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solve(n,days,cost,0);
}


// Memoization


int solve(int n, vector<int>&days, vector<int>&cost,int index,vector<int>&dp){
    if(index>=n) return 0;

    if(dp[index]!=-1) return dp[index];
    //pass for 1 day
    int op1=cost[0]+solve(n,days,cost,index+1,dp);
    
    // pass for 7 days
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);
    int op2=cost[1]+solve(n,days,cost,i,dp);

    // pass for 30 days
    for(i=index;i<n && days[i]<days[index]+30;i++);
    int op3=cost[2]+solve(n,days,cost,i,dp);

    return dp[index]= min(op1,min(op2,op3));
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int>dp(n,-1);
    return solve(n,days,cost,0,dp);
}


// Tabulation method

int solve(int n, vector<int>&days, vector<int>&cost){

    vector<int>dp(n+1,INT_MAX);

    dp[n]=0;

    for(int k=n-1;k>=0;k--){
        //pass for 1 day
        int op1=cost[0]+ dp[k+1];
        
        // pass for 7 days
        int i;
        for(i=k;i<n && days[i]<days[k]+7;i++);
        int op2=cost[1]+dp[i];
    
        // pass for 30 days
        for(i=k;i<n && days[i]<days[k]+30;i++);
        int op3=cost[2]+dp[i];

        dp[k]=min(op1,min(op2,op3));
    }
     
    return  dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int>dp(n,-1);
    return solve(n,days,cost);
}