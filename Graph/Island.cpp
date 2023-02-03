// https://leetcode.com/problems/number-of-islands/

// Type of number of connected components

// BFS = TC --> O(N^2), SC --> O(N^2)

#include <vector>
#include <queue>
using namespace std;

class Solution
{
    int leetDist[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int gfgDist[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    bool isValid(int i, int j, int row, int col)
    {
        return (i >= 0 and i < row and j >= 0 and j < col);
    }

public:
    void dfs(int i, int j, vector<vector<char>> &g)
    {
        int rows = g.size();
        int cols = g[0].size();

        if (!isValid(i, j, rows, cols) or g[i][j] == '0')
            return;

        g[i][j] = '0';

        dfs(i + 1, j, g);
        dfs(i, j + 1, g);
        dfs(i - 1, j, g);
        dfs(i, j - 1, g);
    }

    void bfs(int iRow, int jCol, vector<vector<bool>> &visited, vector<vector<char>> &g)
    {
        int rows = g.size();
        int cols = g[0].size();

        queue<pair<int, int>> q;
        q.push({iRow, jCol});

        visited[iRow][jCol] = true;

        while (!q.empty())
        {
            int qrow = q.front().first;
            int qcol = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = qrow + leetDist[i][0];
                int ncol = qcol + leetDist[i][1];

                if (isValid(nrow, ncol, rows, cols) and !visited[nrow][ncol] and g[nrow][ncol] == '1')
                {
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &g)
    {
        int rows = g.size();
        int cols = g[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, 0));
        int ans = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (!visited[i][j] and g[i][j] == '1')
                    ans++, dfs(i, j, g);
            }
        }

        return ans;
    }
};