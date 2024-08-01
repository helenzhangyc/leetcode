#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<pair<int, string>> combine;
        int num = names.size();
        for (int i = 0; i < num; ++i)
        {
            combine.push_back(make_pair(heights[i], names[i]));
        }
        sort(combine.begin(), combine.end());

        vector<string> result;
        for (int i = num - 1; i >= 0; --i)
        {
            result.push_back(combine[i].second);
        }
        return result;
    }
};