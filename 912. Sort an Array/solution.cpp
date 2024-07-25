class Solution
{
public:
    vector<int> mergesort(vector<int> &nums)
    {
        int length = nums.size();
        if (length > 1)
        {
            int mid = length / 2;
            vector<int> left_half(nums.begin(), nums.begin() + mid);
            vector<int> right_half(nums.begin() + mid, nums.end());

            mergesort(left_half);
            mergesort(right_half);

            int i = 0;
            int j = 0;
            int k = 0;
            while (i < left_half.size() && j < right_half.size())
            {
                if (left_half[i] < right_half[j])
                {
                    nums[k] = left_half[i];
                    i++;
                }
                else
                {
                    nums[k] = right_half[j];
                    j++;
                }
                k++;
            }
            while (i < left_half.size())
            {
                nums[k] = left_half[i];
                i++;
                k++;
            }
            while (j < right_half.size())
            {
                nums[k] = right_half[j];
                j++;
                k++;
            }
        }
        return nums;
    }

    vector<int> sortArray(vector<int> &nums)
    {
        return mergesort(nums);
    }
};