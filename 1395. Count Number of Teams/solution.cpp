class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int result = 0;
        int num = rating.size();
        // loop through the middle candidate
        for (int i = 1; i <= num - 2; ++i)
        {
            for (int left = 0; left < i; ++left)
            {
                for (int right = i + 1; right < num; ++right)
                {
                    if ((rating[left] < rating[i] && rating[i] < rating[right]) || (rating[left] > rating[i] && rating[i] > rating[right]))
                    {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};