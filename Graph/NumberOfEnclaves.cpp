// https://leetcode.com/problems/number-of-enclaves/
// Apply DFS from all corner sides

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
    int dirX[4] = {-1, 0, 1, 0};
    int dirY[4] = {0, 1, 0, -1};

public:
    bool isValid(int i, int j, int rows, int cols)
    {
        return (i >= 0 and i < rows and j >= 0 and j < cols);
    }

    void dfs(int x, int y, vector<vector<int>> &g, vector<vector<bool>> &visited)
    {
        int rows = g.size();
        int cols = g[0].size();

        visited[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dirX[i];
            int newY = y + dirY[i];

            if (isValid(newX, newY, rows, cols) and visited[newX][newY] == false and g[newX][newY] == 1)
                dfs(newX, newY, g, visited);
        }
    }

    int numEnclaves(vector<vector<int>> &g)
    {
        int rows = g.size();
        int cols = g[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < cols; i++)
        {
            if (!visited[0][i] and g[0][i] == 1)
                dfs(0, i, g, visited);

            if (!visited[rows - 1][i] and g[rows - 1][i] == 1)
                dfs(rows - 1, i, g, visited);
        }

        for (int i = 0; i < rows; i++)
        {
            if (!visited[i][0] and g[i][0] == 1)
                dfs(i, 0, g, visited);

            if (!visited[i][rows - 1] and g[i][rows - 1] == 1)
                dfs(i, cols - 1, g, visited);
        }

        int ans = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (!visited[i][j] and g[i][j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};