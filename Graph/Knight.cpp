// https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1

#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

class Solution
{
    int deltaRow[8] = {-1, -1, -2, -2, 1, 1, 2, 2};
    int deltaCol[8] = {2, -2, 1, -1, 2, -2, -1, 1};

public:
    bool isValid(int i, int j, int n)
    {
        return (i >= 0 and i < n and j >= 0 and j < n);
    }

    int bfs(int sr, int sc, int tr, int tc, int n, vector<vector<bool>> &visited)
    {
        queue<pair<pair<int, int>, int>> q;
        q.push({{sr, sc}, 0});

        visited[sr][sc] = true;

        while (not q.empty())
        {
            int qr = q.front().first.first;
            int qc = q.front().first.second;
            int time = q.front().second;
            q.pop();

            if (qr == tr and qc == tc)
                return time;

            for (int i = 0; i < 8; i++)
            {
                int nqr = qr + deltaRow[i];
                int nqc = qc + deltaCol[i];

                if (isValid(nqr, nqc, n) and !visited[nqr][nqc])
                {
                    visited[nqr][nqc] = true;
                    q.push({{nqr, nqc}, time + 1});
                }
            }
        }

        return -1;
    }

    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n)
    {
        int sr = KnightPos[0] - 1;
        int sc = KnightPos[1] - 1;

        int tr = TargetPos[0] - 1;
        int tc = TargetPos[1] - 1;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        return bfs(sr, sc, tr, tc, n, visited);
    }
};
