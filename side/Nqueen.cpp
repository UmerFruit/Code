#include "Headers.h"
// N queens backtracking solution
 vector<vector<int> > board;
 int n;
 bool isSafe(int row, int col)
 {
    //check row
    for(int i = 0; i < col; i++)
    {
       if(board[row][i] == 1)
          return false;
    }
    //check upper left diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
       if(board[i][j] == 1)
          return false;
    }
    //check lower left diagonal
    for(int i = row, j = col; i < n && j >= 0; i++, j--)
    {
       if(board[i][j] == 1)
          return false;
    }
    return true;
 }
 bool solveNQ(int col)
 {
    if(col >= n)
       return true;
    for(int i = 0; i < n; i++)
    {
       if(isSafe(i, col))
       {
          board[i][col] = 1;
          if(solveNQ(col + 1))
             return true;
          board[i][col] = 0;
       }
    }
    return false;
 }

// int main()
// {
//    cin > > n;
//    board.resize(n, vector<int>(n, 0));
//    if(solveNQ(0))
//    {
//       for(int i = 0; i < n; i++)
//       {
//          for(int j = 0; j < n; j++)
//          {
//             cout << board[i][j] << " ";
//          }
//          cout << endl;
//       }
//    }
//    else
//       cout << "No solution" << endl;
//    return 0;
// }
void addsolution(vector<vector<int>> &board, vector<vector<int>> &ans)
{

    int n = board.size();

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
        ans.push_back(temp);
    }
}
bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{    // same row
    int x = row, y = col;
    for (int i = 0; i < col; i++)
        if (board[row][i] == 1)
            return false;

    // lower left diagonal
    while (y >= 0 && x < n)
    {
        if (board[x][y] == 1)
            return false;
        y--;
        x++;
    }
    x = row, y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x--, y--;
    }

    return true;
}
void solve(vector<vector<int>> &board, vector<vector<int>> &ans, int col, int n)
{

    if (col == n)
    {
        addsolution(board, ans);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 1;
            solve(board, ans, col + 1, n);
            board[row][col] = 0;
        }
    }
}
vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    int i = 0;
    solve(board, ans, i, n);
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> ans = nQueens(n);
   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}