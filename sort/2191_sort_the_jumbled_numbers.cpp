class Solution
{
public:
    int mapNumber(int num, vector<int> &mapping)
    {
        if (num == 0)
        {
            return mapping[0];
        }
        int multiply = 1;
        int result = 0;
        while (num != 0)
        {
            int curr_digit = num % 10;
            int mapped = mapping[curr_digit];
            result += mapped * multiply;
            multiply *= 10;
            num /= 10;
        }
        return result;
    }

    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        vector<pair<int, int>> numPair;
        for (auto i : nums)
        {
            numPair.push_back(make_pair(i, mapNumber(i, mapping)));
        }
        sort(numPair.begin(), numPair.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return a.second < b.second; });
        vector<int> result;
        for (auto i : numPair)
        {
            result.push_back(i.first);
        }
        return result;
    }
};