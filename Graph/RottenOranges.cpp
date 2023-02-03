// https://leetcode.com/problems/rotting-oranges/

// TC = O(N*M)

#include <vector>
#include <queue>
using namespace std;

class Solution
{
    int deltaRow[4] = {-1, 0, 1, 0};
    int deltaCol[4] = {0, 1, 0, -1};

public:
    int orangesRotting(vector<vector<int>> &g)
    {
        int rows = g.size();
        int cols = g[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (g[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }
        int ans = 0;

        while (!q.empty())
        {
            int qr = q.front().first.first;
            int qc = q.front().first.second;
            int time = q.front().second;

            ans = time;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nqr = qr + deltaRow[i];
                int nqc = qc + deltaCol[i];

                if (nqr >= 0 and nqr < rows and nqc >= 0 and nqc < cols and !visited[nqr][nqc] and g[nqr][nqc] == 1)
                {
                    visited[nqr][nqc] = true;
                    q.push({{nqr, nqc}, time + 1});
                }
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (g[i][j] == 1 and !visited[i][j])
                {
                    ans = -1;
                    break;
                }
            }
        }

        return ans;
    }
};