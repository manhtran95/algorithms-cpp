#include <bits/stdc++.h>
using std::cout;
using std::vector;
using std::string;

int col[64] = {};
int diag1[64] = {};
int diag2[64] = {};

void search(int x, int N, vector<vector<string>>& res, vector<string>& board){
    if (x == N){
        vector<string> ans {board};
        res.push_back(ans);
    }
    for (int y=0; y<N; y++){
        if (col[y] || diag1[x+y] || diag2[x-y+N-1]) continue;
        // put queen at (x,y)
        board[x][y] = 'Q';
        col[y] = diag1[x+y] = diag2[x-y+N-1] = 1;
        search(x+1, N, res, board);
        board[x][y] = '.';
        col[y] = diag1[x+y] = diag2[x-y+N-1] = 0;
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board = {};
    for (int i=0; i<n; i++){
        string row = "";
        for (int j=0; j<n; j++){
            row += ".";
        }
        board.push_back(row);
    }
    search(0, n, res, board);
    return res;
}

int main(){
    int N = 4;
    vector<vector<string>> res = solveNQueens(N);
    for (int i=0;i<N; i++){
        for (int j=0; j<N; j++){
            cout << res[i][j] << "\n";
        }
        cout << "\n";
    }
}