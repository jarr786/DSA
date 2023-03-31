 // The N - Queens Puzzle

#include <bits/stdc++.h>

void addsolution(int n,vector<vector<int>>&ans,vector<vector<int>>&board){
    vector<int>temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
        ans.push_back(temp);
}

bool issafe(int row,int col,vector<vector<int>>&board,int n){
    int x=row;
    int y=col;
    // row checking from right to left
    while(y>=0){
        if(board[x][y]==1) return false;
        y--;
    }

    // dignal  checking in upward direction
	x=row;
    y=col;
    while(x>=0 && y>=0){
        if(board[x][y]==1) return false;
        x--;
        y--;
    }

    // dignal  checking in downward direction
	x=row;
    y=col;
    while(x<n && y>=0){
        if(board[x][y]==1) return false;
        x++;
        y--;
    }
    // if we are here then we can place our queen
    return true;
}

void solve(int col,vector<vector<int>>&ans,vector<vector<int>>&board,int n){
    if(col==n){
        addsolution(n,ans,board);
        return;
    }
    for(int row=0;row<n;row++){

        if(issafe(row,col,board,n)){
			//place queen
            board[row][col]=1;
			//recursive call
            solve(col+1,ans,board,n);
			//bktrking
            board[row][col]=0;
        }
    }
}
vector<vector<int>> nQueens(int n)
{
	vector<vector<int>>ans;
    vector<vector<int>>board(n,vector<int>(n,0));

    int col=0;
	solve(col,ans,board,n);

    return ans;
}
 