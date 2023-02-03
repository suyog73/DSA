// https://leetcode.com/problems/flood-fill/

// TC = O(N*M)

#include <vector>
using namespace std;

class Solution
{
    int deltaRow[4] = {-1, 0, 1, 0};
    int deltaCol[4] = {0, 1, 0, -1};

public:
    void dfs(int sr, int sc, vector<vector<int>> &im, vector<vector<int>> &ans, int color, int iniColor)
    {
        int rows = im.size();
        int cols = im[0].size();

        ans[sr][sc] = color;

        for (int i = 0; i < 4; i++)
        {
            int nrow = sr + deltaRow[i];
            int ncol = sc + deltaCol[i];

            if (nrow >= 0 and nrow < rows and ncol >= 0 and ncol < cols and ans[nrow][ncol] != color and im[nrow][ncol] == iniColor)
            {
                dfs(nrow, ncol, im, ans, color, iniColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &im, int sr, int sc, int color)
    {
        int rows = im.size();
        int cols = im[0].size();

        vector<vector<int>> ans = im;

        int iniColor = im[sr][sc];

        dfs(sr, sc, im, ans, color, iniColor);
    }
};