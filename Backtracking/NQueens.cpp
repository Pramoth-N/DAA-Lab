// N Queens Problem

#include <bits/stdc++.h>

using namespace std;

bool backtrack(vector<vector<int>> &board,vector<bool> &digonal1,vector<bool> &digonal2,vector<bool> &row,int i){
    int n = board.size();
    if(i==board.size()){
        for(int j=0;j<board.size();j++){
            for(int k=0;k<board.size();k++){
                cout<<board[j][k]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    for(int j=0;j<board.size();j++){
        if(row[j]==false && digonal1[i+j]==false && digonal2[i-j+n-1]==false){
            board[i][j]=1;
            row[j]=true;
            digonal1[i+j]=true;
            digonal2[i-j+n-1]=true;
            if(backtrack(board,digonal1,digonal2,row,i+1)){
                return true;
            }
            board[i][j]=0;
            row[j]=false;
            digonal1[i+j]=false;
            digonal2[i-j+n-1]=false;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<bool> digonal1(2*n-1,false) , digonal2(2*n-1,false) , row(n,false);

    backtrack(board,digonal1,digonal2,row,0);
}