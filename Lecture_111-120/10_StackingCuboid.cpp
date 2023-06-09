/*
1691. Maximum Height by Stacking Cuboids

Given n cuboids where the dimensions of the ith cuboid is 
cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose 
a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j 
if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. 
You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.
 
Example 1:



Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.
*/

class Solution {
    bool check(vector<int>base,vector<int>newbox){
        if(newbox[0]<=base[0] && newbox[1]<=base[1] && newbox[2]<=base[2]) return true;
        else return false;
    }
    int solvetab(int n, vector<vector<int>>& a){
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                // including 
                int inc=0;
                if(prev==-1 || check(a[curr],a[prev])) inc= a[curr][2]+nextRow[curr+1];
                // excluding 
                int exc= nextRow[prev+1];
                currRow[prev+1]=max(inc,exc);
            }
            nextRow=currRow;
        }
        return currRow[0];
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n=cuboids.size();
        for(auto &i:cuboids){
            sort(i.begin(),i.end());
        }
        sort(cuboids.begin(),cuboids.end());
        return solvetab(n,cuboids);
    }
};