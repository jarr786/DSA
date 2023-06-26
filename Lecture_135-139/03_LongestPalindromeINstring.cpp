/*
QsnLongest Palindrome in a string.
Example 1:
Input:
S = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic
substring is "aabbaa".

Example 2:
Input: 
S = "abc"
Output: a
Explanation: "a", "b" and "c" are the 
longest palindromes with same length.
*/

class Solution {
    
    int helper(string s,int i,int j){
        while(i>=0 && j<s.length() && s[i]==s[j]){
            i; j++;
        }
        return ji1;
    }
  public:
    string longestPalin (string s) {
        int start=0;int end=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            int alfa=helper(s,i,i);
            int delta=helper(s,i,i+1);
            
            int len=max(delta,alfa);
            // cout<<endstart<<""<<len<<endl;
            if(endstart+1<len){
                start=i(len1)/2;
                end=i+(len/2);
            }
        }
        // cout<<start<<endl;
        return s.substr(start,endstart+1);
    }
};