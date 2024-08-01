class Solution
{
public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int num_book = books.size();
        vector<int> dp(num_book + 1, 0);
        for (int i = 1; i <= num_book; ++i)
        {
            int width = books[i - 1][0];
            int height = books[i - 1][1];
            dp[i] = dp[i - 1] + height;
            for (int j = i - 1; j > 0 && width + books[j - 1][0] <= shelfWidth; --j)
            {
                height = max(height, books[j - 1][1]);
                width += books[j - 1][0];
                dp[i] = min(dp[i], dp[j - 1] + height);
            }
        }
        return dp[num_book];
    }
};