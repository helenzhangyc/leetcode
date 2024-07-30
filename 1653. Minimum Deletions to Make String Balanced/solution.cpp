class Solution
{
public:
    int minimumDeletions(string s)
    {
        // for every index, find the number of b's before it and the number of a's after it
        int len = s.size();
        vector<int> a(len, 0);
        vector<int> b(len, 0);
        int num_a = 0;
        int num_b = 0;
        for (int i = 0; i < len; ++i)
        {
            b[i] = num_b;
            if (s[i] == 'b')
            {
                num_b++;
            }
            a[len - 1 - i] = num_a;
            if (s[len - 1 - i] == 'a')
            {
                num_a++;
            }
        }
        int result = INT_MAX;
        for (int i = 0; i < len; ++i)
        {
            if (a[i] + b[i] < result)
            {
                result = a[i] + b[i];
            }
        }
        return result;
    }
};