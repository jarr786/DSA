/*
1402. Reducing Dishes
A chef has collected data on the satisfaction level of his n dishes. 
Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to 
cook that dish including previous dishes multiplied by its satisfaction 
level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can 
obtain after dishes preparation.

Dishes can be prepared in any order and the chef can discard some 
dishes to get this maximum value.

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, 
the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.
Example 2:

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
Example 3:

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.
*/

// Memoization
class Solution {
    int solve(vector<int>& satisfaction,int time,int i,vector<vector<int>>&dp){
        if(i>=satisfaction.size()) return 0;
        if(dp[time][i]!=-1) return dp[time][i];
        int inc=(satisfaction[i]*time)+solve(satisfaction,time+1,i+1,dp);
        int exc=0+solve(satisfaction,time,i+1,dp);
        return dp[time][i]=max(inc,exc);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        sort(satisfaction.begin(),satisfaction.end());
        return solve(satisfaction,1,0,dp);
    }
};

// Tabulation
int solvetab(vector<int>& satisfaction){
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int index=n-1;index>=0;index--){
            for(int time=index;time>=0;time--){
                int inc=(satisfaction[index]*(time+1))+dp[time+1][index+1];
                int exc=0+dp[time][index+1];
                dp[time][index]=max(inc,exc);
            }
        }
        return dp[0][0];
    }

//Tabulation space optimization
    int solvetab(vector<int>& satisfaction){
        int n=satisfaction.size();
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        for(int index=n-1;index>=0;index--){
            for(int time=index;time>=0;time--){
                int inc=(satisfaction[index]*(time+1))+next[time+1];
                int exc=0+next[time];
                curr[time]=max(inc,exc);
            }
            next=curr;
        }
        return next[0];
    }    