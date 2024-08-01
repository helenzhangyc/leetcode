#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        // count the frequency of each value
        unordered_map<int, int> frequencyMap;
        for (auto item : nums)
        {
            frequencyMap[item]++;
        }
        sort(nums.begin(), nums.end(), [&frequencyMap](int a, int b)
             {
            if (frequencyMap[a] == frequencyMap[b]) {
                return a > b;
            }
            return frequencyMap[a] < frequencyMap[b]; });
        return nums;
    }
};