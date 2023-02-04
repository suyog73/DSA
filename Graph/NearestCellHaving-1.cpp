// https://leetcode.com/problems/01-matrix/description/
// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<vector<int>> vans;

    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool isValid(int x, int y, int row, int col)
    {
        return (x >= 0 and x < row and y >= 0 and y < col);
    }

    void printQ(queue<pair<int, int>> q)
    {
        while (!q.empty())
        {
            cout << q.front().first << " " << q.front().second << "\n";
            q.pop();
        }

        cout << "\n";
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &m)
    {
        vans.resize(m.size(), vector<int>(m[0].size(), -1));

        // pair of {nodeX, nodeY}
        queue<pair<int, int>> q;

        for (int i = 0; i < m.size(); i++)
            for (int j = 0; j < m[0].size(); j++)
                if (m[i][j] == 0)
                {
                    q.push({i, j});
                    vans[i][j] = 0;
                }

        while (!q.empty())
        {
            // printQ(q);
            int nodeX = q.front().first;
            int nodeY = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int newX = nodeX + dir[i][0];
                int newY = nodeY + dir[i][1];

                if (isValid(newX, newY, m.size(), m[0].size()) and vans[newX][newY] == -1)
                {
                    vans[newX][newY] = vans[nodeX][nodeY] + 1;
                    q.push({newX, newY});
                }
            }
        }

        return vans;
    }
};