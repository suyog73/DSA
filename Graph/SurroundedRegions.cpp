// https://leetcode.com/problems/surrounded-regions/
// https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1

// Apply DFS from all corner sides

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
    int arrX[4] = {0, 1, 0, -1};
    int arrY[4] = {1, 0, -1, 0};

public:
    bool isValid(int i, int j, int row, int col)
    {
        return (i >= 0 and i < row and j >= 0 and j < col);
    }

    void dfs(int x, int y, vector<vector<char>> &b, vector<vector<bool>> &visited)
    {
        int rows = b.size();
        int cols = b[0].size();

        visited[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int newX = x + arrX[i];
            int newY = y + arrY[i];

            if (isValid(newX, newY, rows, cols) and visited[newX][newY] == false and b[newX][newY] == 'O')
                dfs(newX, newY, b, visited);
        }
    }

    void solve(vector<vector<char>> &b)
    {
        int rows = b.size();
        int cols = b[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < cols; i++)
        {
            if (b[0][i] == 'O' and visited[0][i] == false)
                dfs(0, i, b, visited);

            if (b[rows - 1][i] == 'O' and visited[rows - 1][i] == false)
                dfs(rows - 1, i, b, visited);
        }

        for (int i = 0; i < rows; i++)
        {
            if (b[i][0] == 'O' and visited[i][0] == false)
                dfs(i, 0, b, visited);

            if (b[i][rows - 1] == 'O' and visited[i][cols - 1] == false)
                dfs(i, cols - 1, b, visited);
        }

        // for (int i = 0; i < rows; i++)
        // {
        //     for (int j = 0; j < cols; j++)
        //     {
        //         cout << visited[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (b[i][j] == 'O' and visited[i][j] == false)
                    b[i][j] = 'X';
            }
        }
    }
};