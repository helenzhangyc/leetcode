// O(n)
class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        // get number of 1's in nums
        int total = 0;
        int length = nums.size();
        for (auto n : nums)
        {
            if (n == 1)
            {
                total++;
            }
        }
        nums.resize(2 * length);
        copy_n(nums.begin(), length, nums.begin() + length);
        // for each subarray of length total, count the number of 0's
        int curr_result = 0;
        for (int i = 0; i < total; ++i)
        {
            if (nums[i] == 0)
            {
                curr_result++;
            }
        }
        int result = curr_result;
        int i = 0;
        int j = total - 1;
        while (j < 2 * length - 1)
        {
            curr_result = curr_result - (1 - nums[i]) + (1 - nums[j + 1]);
            if (curr_result < result)
            {
                result = curr_result;
            }
            i++;
            j++;
        }
        return result;
    }
};