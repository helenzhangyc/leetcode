#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string &s)
    {
        int len = s.size();
        for (int i = 0; i < len / 2; ++i)
        {
            if (s[i] != s[len - 1 - i])
            {
                return false;
            }
        }
        return true;
    }

    void subpartition(vector<vector<string>> &res, string &s, int idx, vector<string> &curr)
    {
        if (idx == s.size())
        {
            res.push_back(curr);
            return;
        }
        string t;
        for (int i = idx; i < s.size(); ++i)
        {
            t.push_back(s[i]);
            if (isPalindrome(t))
            {
                curr.push_back(t);
                subpartition(res, s, i + 1, curr);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        int idx = 0;
        vector<string> curr;
        subpartition(res, s, idx, curr);
        return res;
    }
};