// https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/

// Problem can be solved using simple bfs
// Here I used tuple with priority queue, to arange values according to question.

#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

#define pii pair<pair<int, int>, int>
#define tp tuple<int, int, int, int>

class Solution
{

    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, 1, -1, 0};

    bool isValid(int i, int j, int rows, int cols)
    {
        return (i >= 0 and i < rows and j >= 0 and j < cols);
    }

    void printTuple(priority_queue<tp, vector<tp>, greater<tp>> pq)
    {
        while (!pq.empty())
        {
            tp tp1 = pq.top();
            pq.pop();
            cout << get<0>(tp1) << " ";
            cout << get<1>(tp1) << " ";
            cout << get<2>(tp1) << " ";
            cout << get<3>(tp1) << "\n";
        }
    }

public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>> &g, vector<int> &p, vector<int> &st, int k)
    {
        vector<vector<int>> vans;
        int rows = g.size();
        int cols = g[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        queue<pii> pq;
        pq.push({{st[0], st[1]}, 0});

        visited[st[0]][st[1]] = true;

        priority_queue<tp, vector<tp>, greater<tp>> tuple_pq;

        if (g[st[0]][st[1]] <= p[1] and g[st[0]][st[1]] >= p[0])
        {
            vector<int> vtp;
            vtp.push_back(st[0]);
            vtp.push_back(st[1]);

            vans.push_back(vtp);
            k--;
        }

        while (not pq.empty())
        {
            int x = pq.front().first.first;
            int y = pq.front().first.second;
            int steps = pq.front().second;
            pq.pop();

            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (isValid(newX, newY, rows, cols) and g[newX][newY] != 0 and !visited[newX][newY])
                {
                    if (g[newX][newY] <= p[1] and g[newX][newY] >= p[0])
                    {
                        tp tp1 = make_tuple(steps + 1, g[newX][newY], newX, newY);
                        tuple_pq.push(tp1);
                    }

                    visited[newX][newY] = true;
                    pq.push({{newX, newY}, steps + 1});
                }
            }
        }

        // printTuple(tuple_pq);

        k = min(k, (int)tuple_pq.size());
        while (k--)
        {
            tp tp1 = tuple_pq.top();
            tuple_pq.pop();

            vector<int> vtp;
            vtp.push_back(get<2>(tp1));
            vtp.push_back(get<3>(tp1));

            vans.push_back(vtp);
        }
        return vans;
    }
};