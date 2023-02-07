// https://leetcode.com/problems/word-ladder/description/

// Space complexity => O(n)
// Time complexity => O(n * 26*m * log(n)) => n = total words and m = word size

#include <vector>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // find element in O(1) while set takes O(log(n)) time
        unordered_set<string> st;

        for (string ss : wordList)
            st.insert(ss);

        queue<pair<string, int>> q;
        q.push({beginWord, 0});

        // Queue will run for number of words times
        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == endWord)
                return steps;

            // it will run for word length * 26 times
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.find(word) != st.end())
                    {
                        q.push({word, steps + 1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};