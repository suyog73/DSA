// https://leetcode.com/problems/word-ladder-ii/description/

#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
private:
    vector<vector<string>> ans;

    void dfs(map<string, int> &mp, vector<string> &seq, string &beginWord, string &endWord)
    {
        if (endWord == beginWord)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());

            return;
        }

        int steps = mp[endWord];

        for (int i = 0; i < endWord.size(); i++)
        {
            char original = endWord[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                endWord[i] = ch;
                if (mp.count(endWord) and mp[endWord] == steps - 1)
                {
                    seq.push_back(endWord);
                    dfs(mp, seq, beginWord, endWord);
                    seq.pop_back();
                }
            }
            endWord[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;

        q.push(beginWord);
        map<string, int> mp;

        st.erase(beginWord);

        mp[beginWord] = 1;
        while (!q.empty())
        {
            string word = q.front();
            q.pop();
            int steps = mp[word];

            if (word == endWord)
                break;

            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word))
                    {
                        q.push(word);
                        mp[word] = steps + 1;

                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        if (mp.count(endWord))
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(mp, seq, beginWord, endWord);
        }

        return ans;
    }
};