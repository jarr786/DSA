#include <bits/stdc++.h> 

// Qsn-cdnjas Rat in a Maze

bool issafe(int x,int y,vector < vector < int >> & arr,vector < vector < bool >>&visited,int n){
    if(x>=0 && x<n && y>=0 && y<n && visited[x][y]==0 && arr[x][y]==1) return true;
    else return false;
}

void solve(int x,int y,vector < vector < int >> & arr,vector < vector < bool >>&visited,vector<string>&ans,string output,int n){
    if(x==n-1 && y==n-1){
        ans.push_back(output);
        return; 
    }
    visited[x][y]=1;

    // making recursive calls if it is safe to go
    //down
    if(issafe(x+1,y,arr,visited,n)){
        solve(x+1,y,arr,visited,ans,output+'D',n);
    }
    //left
    if(issafe(x,y-1,arr,visited,n)){
        solve(x,y-1,arr,visited,ans,output+'L',n);
    }
    //right
    if(issafe(x,y+1,arr,visited,n)){
        solve(x,y+1,arr,visited,ans,output+'R',n);
    }
    //up
    if(issafe(x-1,y,arr,visited,n)){
        solve(x-1,y,arr,visited,ans,output+'U',n);
    }
    // backtracking
    visited[x][y]=0;
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector < string >ans;

    if(arr[0][0]==0) return ans;

    vector < vector < bool >>visited(n,vector<bool>(n,false));
    string output="";

    solve(0,0,arr,visited,ans,output,n);
    return ans;
}