/*
354. Russian Doll Envelopes
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] 
represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height
of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll 
(i.e., put one inside the other).

Note: You cannot rotate an envelope.
 
Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

class Solution {
    static bool comparator(const vector<int>&a,const vector<int>&b){
        if(a[0]<b[0]) return true;
        if(a[0]==b[0]){
            if(a[1]>b[1]) return true;
        }
        return false;
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes){
        int n=envelopes.size();
        // sorting by width
        // if two row has same width then sorting or putting greater height first
        sort(envelopes.begin(),envelopes.end(),comparator);
      //  for(auto i:envelopes) cout<<i[0]<<"---"<<i[1]<<endl;
        // applying longest increasing subsequence on the height colums 
        vector<int>ans;
        ans.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            if(envelopes[i][1]>ans.back()) ans.push_back(envelopes[i][1]);
            else{
                int index=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
                ans[index]=envelopes[i][1];
            }
        }
        // sending size of ans
        return ans.size();
    }
};