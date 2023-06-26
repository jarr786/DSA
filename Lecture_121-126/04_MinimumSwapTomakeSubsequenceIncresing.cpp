/*
801. Minimum Swaps To Make Sequences Increasing
You are given two integer arrays of the same length nums1 
and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].

For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you 
can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and 
nums2 = [5,6,7,8].
Return the minimum number of needed operations to make nums1 
and nums2 strictly increasing. The test cases are generated 
so that the given input always makes it possible.

An array arr is strictly increasing if and only if 
arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].

Example 1:

Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
Output: 1
Explanation: 
Swap nums1[3] and nums2[3]. Then the sequences are:
nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
which are both strictly increasing.
*/

class Solution {
    // Recursive solution
    int solve(vector<int>& nums1, vector<int>& nums2,int index,int swapped){
        if(index==nums1.size()) return 0;
        int ans=INT_MAX;

        int prev1=nums1[index-1];
        int prev2=nums2[index-1];

        // if previously swapped
        if(swapped==1) swap(prev1,prev2);
        
        // right case
        if(nums1[index]>prev1 && nums2[index]>prev2){
            ans=solve(nums1,nums2,index+1,0);
        }
        //case where swap is required
        if(nums1[index]>prev2 && nums2[index]>prev1){
            ans=min(ans,1+solve(nums1,nums2,index+1,1));
        }
        return ans;
    }

    // Memoization solution
    int solveMemo(vector<int>& nums1, vector<int>& nums2,int index,int swapped,vector<vector<int>>&dp){
        if(index==nums1.size()) return 0;

        if(dp[index][swapped]!=-1) return dp[index][swapped];

        int ans=INT_MAX;
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];

        // if previously swapped
        if(swapped==1) swap(prev1,prev2);
        
        // right case
        if(nums1[index]>prev1 && nums2[index]>prev2){
            ans=solveMemo(nums1,nums2,index+1,0,dp);
        }
        //case where swap is required
        if(nums1[index]>prev2 && nums2[index]>prev1){
            ans=min(ans,1+solveMemo(nums1,nums2,index+1,1,dp));
        }
        return dp[index][swapped]=ans;
    }

    // Tabulation
    int solveTab(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int index=n-1;index>=1;index--){
            for(int swapped=0;swapped<=1;swapped++){
                int ans=INT_MAX;
                int prev1=nums1[index-1];
                int prev2=nums2[index-1];
        
                // if previously swapped
                if(swapped==1) swap(prev1,prev2);
                
                // right case
                if(nums1[index]>prev1 && nums2[index]>prev2){
                    ans=dp[index+1][0];
                }
                //case where swap is required
                if(nums1[index]>prev2 && nums2[index]>prev1){
                    ans=min(ans,1+dp[index+1][1]);
                }
                dp[index][swapped]=ans;
            }
        }
        return dp[1][0];
    }
    // Tabulation space optimization
    int solveTabSO(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size();
        vector<int>curr(2,0);
        vector<int>next(2,0);
        for(int index=n-1;index>=1;index--){
            for(int swapped=0;swapped<=1;swapped++){
                int ans=INT_MAX;
                int prev1=nums1[index-1];
                int prev2=nums2[index-1];
        
                // if previously swapped
                if(swapped==1) swap(prev1,prev2);
                
                // right case
                if(nums1[index]>prev1 && nums2[index]>prev2){
                    ans=next[0];
                }
                //case where swap is required
                if(nums1[index]>prev2 && nums2[index]>prev1){
                    ans=min(ans,1+next[1]);
                }
                curr[swapped]=ans;
            }
            next=curr;
        }
        return curr[0];
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        int n=nums1.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));

        // return solve(nums1,nums2,1,0);
        // return solveMemo(nums1,nums2,1,0,dp);
        // return solveTab(nums1,nums2);
        return solveTabSO(nums1,nums2);
    }
};


/*
Approach:
1.if value is greater than previous in both 
then go to next index
2.otherwise swapped is there on following conditions.
*/