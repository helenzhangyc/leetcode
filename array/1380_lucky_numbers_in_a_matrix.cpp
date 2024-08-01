#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> retval;
        int row = matrix.size();
        int col = matrix[0].size();
        int curr_min = INT_MAX;
        int min_col_index = 0;
        for (int r = 0; r < row; ++r)
        {
            curr_min = INT_MAX;
            // find min in each row
            for (int c = 0; c < col; ++c)
            {
                if (matrix[r][c] < curr_min)
                {
                    curr_min = matrix[r][c];
                    min_col_index = c;
                }
            }
            // check if the element matrix[r][min_col_index] is the max in the column min_col_index
            int curr_max = INT_MIN;
            for (int rr = 0; rr < row; ++rr)
            {
                if (matrix[rr][min_col_index] > curr_max)
                {
                    curr_max = matrix[rr][min_col_index];
                }
            }
            if (curr_min == curr_max)
            {
                retval.push_back(curr_min);
            }
        }
        return retval;
    }
};