// Qsn-cdnjs  Sudoku Solver

#include <bits/stdc++.h> 

bool issafe(int row,int col,vector<vector<int>>& sudoku,int val){
    for(int i=0;i<9;i++){
        // chking for row
        if(sudoku[row][i]==val) return false;
        // chking for col
        if(sudoku[i][col]==val) return false;
        //checking for 3*3 matrix
        if(sudoku[3*(row/3)+i/3][3*(col/3)+i%3]==val) return false;
    }
    return true;
}

bool solve(vector<vector<int>>& sudoku){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){

            if(sudoku[i][j]==0){  

                for(int val=1;val<=9;val++){

                    if(issafe(i,j,sudoku, val)){
                        sudoku[i][j]=val;
                        //recursive call
                        bool isAageSolutionPossible=solve(sudoku);

                        if(isAageSolutionPossible==true){
                            return true;
                        }
                        // backtracking
                        else{
                            sudoku[i][j]=0;
                        }
                    }
                }

                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}