/*
Longest Arithmetic Progression
Given an array called A[] of sorted integers having no duplicates, 
find the length of the Longest Arithmetic Progression (LLAP) in it.

Example 1:
Input:
N = 6
set[] = {1, 7, 10, 13, 14, 19}
Output: 4
Explanation: The longest arithmetic 
progression is {1, 7, 13, 19}.
*/

// Recursive Memoization

class Solution{   
    int solve(int A[],int i,int diff, map<int,int>dp[]){
        if(i<0) return 0;
        
        if(dp[i].count(diff)) return dp[i][diff];
        
        int ans=0;
        for(int j=i-1;j>=0;j--){
            if(A[i]-A[j]==diff){
                ans=max(ans,1+solve(A,j,diff,dp));
            }
        }
        return dp[i][diff]=ans;
    } 

    // solve, solve 2 function are doing same thing

    int solve2(int A[],int i,int prev,int diff,map<int,int>dp[]){
        if(prev<0) return 0;
        
        if(dp[i][diff]!=0) return dp[i][diff];
        
        int ans=0;
        if(A[i]-A[prev]==diff){
            ans+= 1+solve2(A,prev,prev-1,diff,dp);
        }
        else{
            ans+= 0+solve2(A,i,prev-1,diff,dp);
        }
        return dp[i][diff]=ans;
    }
public:
    int lengthOfLongestAP(int A[], int n) {
        if(n<=2) return n;
        
        // <diff,length> at index
        map<int,int>dp[n+1];
        
        int ans=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int diff=A[j]-A[i];
                // ans=max(ans,2+solve(A,i,diff,dp));
                ans=max(ans,2+solve2(A,i,i-1,diff,dp));
            }
        }
        return ans;
    }
};


// Tabulation

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        if(n<=2) return n;
        int ans=0;
        unordered_map<int,int>dp[n+1];
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=A[i]-A[j];
                
                int count=1;
                // checking if ans already exist
                if(dp[j].count(diff)) count=dp[j][diff];
                // uppadating answer
                dp[i][diff]=1+count;
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};