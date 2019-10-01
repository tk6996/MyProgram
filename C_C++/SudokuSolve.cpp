#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        vector<vector<vector<char>>> gar = garbage(board);
        solve(board, gar);
    }
    bool solve(vector<vector<char>> &board, vector<vector<vector<char>>> &gar)
    {
        int minimun_size = 10;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (!gar[i][j].empty() && minimun_size > gar[i][j].size())
                {
                    minimun_size = gar[i][j].size();
                }
            }
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (minimun_size == gar[i][j].size())
                {
                    for (int k = 0; k < gar[i][j].size(); k++)
                    {
                        board[i][j] = gar[i][j][k];
                        vector<vector<vector<char>>> buffer = gar;
                        gar[i][j].clear();
                        if (!clear_garbage(board, gar, i, j))
                        {
                            board[i][j] = '.';
                            gar = buffer;
                        }
                        else
                        {
                            if (solve(board, gar))
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.';
                                gar = buffer;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool clear_garbage(vector<vector<char>> &board, vector<vector<vector<char>>> &gar, int row, int col)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == '.')
            {
                for (int ind = 0; ind < gar[i][col].size(); ind++)
                {
                    if (board[row][col] == gar[i][col][ind])
                    {
                        gar[i][col].erase(gar[i][col].begin() + ind);
                        if (gar[i][col].empty())
                        {
                            return false;
                        }
                    }
                }
            }
        }
        for (int j = 0; j < 9; j++)
        {
            if (board[row][j] == '.')
            {
                for (int ind = 0; ind < gar[row][j].size(); ind++)
                {
                    if (board[row][col] == gar[row][j][ind])
                    {
                        gar[row][j].erase(gar[row][j].begin() + ind);
                        if (gar[row][j].empty())
                        {
                            return false;
                        }
                    }
                }
            }
        }
        for (int i = 3 * (row / 3); i < 3 * (row / 3) + 3; i++)
        {
            for (int j = 3 * (col / 3); j < 3 * (col / 3) + 3; j++)
            {
                if (board[i][j] == '.' && i != row && j != col)
                {
                    for (int ind = 0; ind < gar[i][j].size(); ind++)
                    {
                        if (board[row][col] == gar[i][j][ind])
                        {
                            gar[i][j].erase(gar[i][j].begin() + ind);
                            if (gar[i][j].empty())
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
    vector<vector<vector<char>>> garbage(vector<vector<char>> &board)
    {
        vector<vector<vector<char>>> gar;
        for (int i = 0; i < 9; i++)
        {
            gar.push_back({});
            for (int j = 0; j < 9; j++)
            {
                gar[i].push_back({});
                if (board[i][j] == '.')
                {
                    for (int k = 0; k < 9; k++)
                    {
                        board[i][j] = '1' + k;
                        if (checkrow(i, j, board) && checkcolumn(i, j, board) && checkbox(i, j, board))
                            gar[i][j].push_back('1' + k);
                        board[i][j] = '.';
                    }
                }
            }
        }
        return gar;
    }
    bool checkrow(int row, int column, vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            if (i == row)
                continue;
            if (board[i][column] == board[row][column])
                return false;
        }
        return true;
    }
    bool checkcolumn(int row, int column, vector<vector<char>> &board)
    {
        for (int j = 0; j < 9; j++)
        {
            if (j == column)
                continue;
            if (board[row][j] == board[row][column])
                return false;
        }
        return true;
    }
    bool checkbox(int row, int column, vector<vector<char>> &board)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == row % 3 && j == column % 3)
                    continue;
                if (board[(row / 3) * 3 + i][(column / 3) * 3 + j] == board[row][column])
                    return false;
            }
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
    vector<vector<char>> board(9, vector<char>(9, 0));
    int last = 81, index = 0;
    while (index < last)
    {
        char a;
        cin >> a;
        if ((a >= '1' && a <= '9') || (a == '.'))
            board[index / 9][index % 9] = a, index++;
    }
    Solution A;
    A.solveSudoku(board);
    for (auto &&row : board)
    {
        for (auto &&colrow : row)
        {
            cout << colrow << " ";
        }
        cout << endl;
    }
    return 0;
}
