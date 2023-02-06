// https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
// Time => O(n*m) + O(n*m + log(n*m))

#include <vector>
#include <set>
using namespace std;

class Solution
{
private:
    set<vector<pair<int, int>>> st;

    int dirX[4] = {0, 0, 1, -1};
    int dirY[4] = {1, -1, 0, 0};

    bool isValid(int x, int y, int row, int col)
    {
        return (x >= 0 and x < row and y >= 0 and y < col);
    }

    void dfs(int x, int y, vector<vector<int>> &g, vector<vector<bool>> &visited, int baseX, int baseY, vector<pair<int, int>> &v)
    {
        int rows = g.size();
        int cols = g[0].size();

        int deltaX = x - baseX;
        int deltaY = y - baseY;

        v.push_back({deltaX, deltaY});

        visited[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dirX[i];
            int newY = y + dirY[i];

            if (isValid(newX, newY, rows, cols) and !visited[newX][newY] and g[newX][newY])
            {
                dfs(newX, newY, g, visited, baseX, baseY, v);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &g)
    {
        int rows = g.size();
        int cols = g[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int ans = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (!visited[i][j] and g[i][j])
                {
                    vector<pair<int, int>> v;
                    dfs(i, j, g, visited, i, j, v);
                    st.insert(v);
                }
            }
        }

        return st.size();
    }
};