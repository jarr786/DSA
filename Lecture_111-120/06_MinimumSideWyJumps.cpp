/*
1824. Minimum Sideway Jumps
There is a 3 lane road of length n that consists of n + 1 
points labeled from 0 to n. A frog starts at point 0 in the 
second lane and wants to jump to point n. However, there could be obstacles along the way.

You are given an array obstacles of length n + 1 where each 
obstacles[i] (ranging from 0 to 3) describes an obstacle on 
the lane obstacles[i] at point i. If obstacles[i] == 0, there 
are no obstacles at point i. There will be at most one obstacle 
in the 3 lanes at each point.

For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
The frog can only travel from point i to point i + 1 on the same 
lane if there is not an obstacle on the lane at point i + 1. To avoid 
obstacles, the frog can also perform a side jump to jump to another lane 
(even if they are not adjacent) at the same point if there is no obstacle on the new lane.

For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
Return the minimum number of side jumps the frog needs to reach any lane at 
point n starting from lane 2 at point 0.

Note: There will be no obstacles on points 0 and n.

Example 1:
Input: obstacles = [0,1,2,3,0]
Output: 2 
Explanation: The optimal solution is shown by the arrows above. 
There are 2 side jumps (red arrows).
Note that the frog can jump over obstacles only when making side 
jumps (as shown at point 2).
*/

// Recursive 
class Solution {
    int solve(vector<int>& ob,int currpos,int currlane){
        if(currpos==ob.size()-1) return 0;
        if(ob[currpos+1]!=currlane){
            return solve(ob,currpos+1,currlane);
        }
        else{
            int ans=INT_MAX;
            for(int i=1;i<=3;i++){
                if(i!=currlane && ob[currpos]!=i) ans=min(ans,1+solve(ob,currpos,i));
            }
            return ans;
        }
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles,0,2);
    }
};


// Memoization
class Solution {
    int solve(vector<int>& ob,int currpos,int currlane,vector<vector<int>>&dp){
        if(currpos==ob.size()-1) return 0;
        if(dp[currlane][currpos]!=-1) return dp[currlane][currpos];

        if(ob[currpos+1]!=currlane){
            return solve(ob,currpos+1,currlane,dp);
        }
        else{
            int ans=INT_MAX;
            for(int i=1;i<=3;i++){
                if(i!=currlane && ob[currpos]!=i) ans=min(ans,1+solve(ob,currpos,i,dp));
            }
            dp[currlane][currpos]=ans;
            return dp[currlane][currpos];
        }
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<vector<int>>dp(4,vector<int>(n ,-1));
        return solve(obstacles,0,2,dp);
    }
};

// Tabulation
class Solution {
    int solve(vector<int>& ob,int currpos,int currlane,vector<vector<int>>&dp){
        if(currpos==ob.size()-1) return 0;
        if(dp[currlane][currpos]!=-1) return dp[currlane][currpos];

        if(ob[currpos+1]!=currlane){
            return solve(ob,currpos+1,currlane,dp);
        }
        else{
            int ans=INT_MAX;
            for(int i=1;i<=3;i++){
                if(i!=currlane && ob[currpos]!=i) ans=min(ans,1+solve(ob,currpos,i,dp));
            }
            dp[currlane][currpos]=ans;
            return dp[currlane][currpos];
        }
    }
    int solvetab(vector<int>& ob){
        int n=ob.size();
        vector<vector<int>>dp(4,vector<int>(n ,INT_MAX));
        dp[0][n-1]=0;
        dp[1][n-1]=0;
        dp[2][n-1]=0;
        dp[3][n-1]=0;
        for(int currpos=n-2;currpos>=0;currpos--){
            for(int currlane=1;currlane<=3;currlane++){
                if(ob[currpos+1]!=currlane){
                    dp[currlane][currpos]=dp[currlane][currpos+1];
                }
                else{
                    int ans=INT_MAX;
                    for(int i=1;i<=3;i++){
                        if(i!=currlane && ob[currpos]!=i){
                            ans=min(ans,1+dp[i][currpos+1]);
                        }
                    }
                    dp[currlane][currpos]=ans;
                }
            }
        }
        return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size();
        return solvetab(obstacles);
    }
};


// Tabulation Space optmization
class Solution {
    int solve(vector<int>& ob,int currpos,int currlane,vector<vector<int>>&dp){
        if(currpos==ob.size()-1) return 0;
        if(dp[currlane][currpos]!=-1) return dp[currlane][currpos];

        if(ob[currpos+1]!=currlane){
            return solve(ob,currpos+1,currlane,dp);
        }
        else{
            int ans=INT_MAX;
            for(int i=1;i<=3;i++){
                if(i!=currlane && ob[currpos]!=i) ans=min(ans,1+solve(ob,currpos,i,dp));
            }
            dp[currlane][currpos]=ans;
            return dp[currlane][currpos];
        }
    }
    int solvetab(vector<int>& ob){
        int n=ob.size();
        vector<int>curr(4,INT_MAX);
        vector<int>next(4,0);
        for(int currpos=n-2;currpos>=0;currpos--){
            for(int currlane=1;currlane<=3;currlane++){
                if(ob[currpos+1]!=currlane){
                    curr[currlane]=next[currlane];
                }
                else{
                    int ans=INT_MAX;
                    for(int i=1;i<=3;i++){
                        if(i!=currlane && ob[currpos]!=i){
                            ans=min(ans,1+next[i]);
                        }
                    }
                    curr[currlane]=ans;
                }
            }
            next=curr;
        }
        return min(curr[2],min(1+curr[1],1+curr[3]));
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size();
        return solvetab(obstacles);
    }
};
