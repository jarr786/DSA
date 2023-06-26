/*
1218. Longest Arithmetic Subsequence of Given Difference

Given an integer array arr and an integer difference, return
 the length of the longest subsequence in arr which is an 
 arithmetic sequence such that the difference between adjacent
  elements in the subsequence equals difference.

Example 1:
Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].

Example 2:
Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.

Example 3:
Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].
*/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int>map;
        int n=arr.size();
        map[arr[0]]=1;
        for(int i=1;i<n;i++){
            int x=arr[i]-diff;
            if(map.find(x)!=map.end()){
                map[arr[i]]=1+map[x];
            }
            else map[arr[i]]=1;
        }
        int ans=1;
        for(auto i:map){
            ans=max(ans,i.second);
        }
        return ans;
    }
};