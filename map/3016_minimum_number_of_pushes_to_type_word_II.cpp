class Solution
{
public:
    int minimumPushes(string word)
    {
        // sort the letters in word by frequencies in non-increasing order
        // count the frequency of each character
        unordered_map<char, int> count;
        for (auto c : word)
        {
            count[c]++;
        }
        vector<pair<char, int>> freqMap(count.begin(), count.end());
        sort(freqMap.begin(), freqMap.end(), [](pair<char, int> &a, pair<char, int> &b)
             {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second; });
        int result = 0;
        int push = 1;
        int key = 8;
        for (auto p : freqMap)
        {
            result += push * p.second;
            key--;
            if (key == 0)
            {
                key = 8;
                push++;
            }
        }
        return result;
    }
};