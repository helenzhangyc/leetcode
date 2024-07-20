#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        int row = rowSum.size();
        int col = colSum.size();
        vector<vector<int>> retval(row, vector<int>(col));

        unsigned long long sum_rowSum = 0;
        unsigned long long sum_colSum = 0;

        for (int i = 0; i < row; ++i)
        {
            sum_rowSum += rowSum[i];
        }
        for (int i = 0; i < col; ++i)
        {
            sum_colSum += colSum[i];
        }

        while (sum_rowSum != 0 && sum_colSum != 0)
        {
            int min_row_index = 0;
            int min_row = INT_MAX;
            int min_col_index = 0;
            int min_col = INT_MAX;
            for (int i = 0; i < row; ++i)
            {
                if (rowSum[i] < min_row && rowSum[i] != 0)
                {
                    min_row = rowSum[i];
                    min_row_index = i;
                }
            }
            for (int j = 0; j < col; ++j)
            {
                if (colSum[j] < min_col && colSum[j] != 0)
                {
                    min_col = colSum[j];
                    min_col_index = j;
                }
            }
            int min_total = min(min_row, min_col);

            retval[min_row_index][min_col_index] += min_total;
            rowSum[min_row_index] -= min_total;
            colSum[min_col_index] -= min_total;
            sum_rowSum -= min_total;
            sum_colSum -= min_total;
        }
        return retval;
    }
};