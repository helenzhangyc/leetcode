class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        vector<int> rangeSum;
        int length = nums.size();
        for (int i = 0; i < length; ++i)
        {
            // compute the range sum starting from i
            int sum = nums[i];
            rangeSum.push_back(sum);
            for (int j = i + 1; j < length; ++j)
            {
                sum += nums[j];
                rangeSum.push_back(sum);
            }
        }
        sort(rangeSum.begin(), rangeSum.end());
        unsigned long long result = 0;
        for (int i = left - 1; i <= right - 1; ++i)
        {
            result += (unsigned long long)rangeSum[i];
            result %= (unsigned long long)(1e9 + 7);
        }
        return result;
    }
};