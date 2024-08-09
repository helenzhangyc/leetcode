class Solution
{
public:
    bool isMagic(vector<vector<int>> &grid)
    {
        // check if it contains distinct number from 1 to 9
        set<int> num;
        for (int r = 0; r < 3; ++r)
        {
            for (int c = 0; c < 3; ++c)
            {
                if (grid[r][c] < 1 || grid[r][c] > 9)
                {
                    return false;
                }
                num.insert(grid[r][c]);
            }
        }
        if (num.size() != 9)
        {
            // there is repeating number from 1 to 9 in grid
            return false;
        }
        // check sum
        int sum = grid[0][0] + grid[0][1] + grid[0][2];
        // row sum
        for (int r = 1; r < 3; ++r)
        {
            int currSum = 0;
            for (int c = 0; c < 3; ++c)
            {
                currSum += grid[r][c];
            }
            if (currSum != sum)
            {
                return false;
            }
        }
        // col sum
        for (int c = 0; c < 3; ++c)
        {
            int currSum = 0;
            for (int r = 0; r < 3; ++r)
            {
                currSum += grid[r][c];
            }
            if (currSum != sum)
            {
                return false;
            }
        }
        // diagonal sum
        if (grid[0][0] + grid[1][1] + grid[2][2] != sum)
        {
            return false;
        }
        if (grid[0][2] + grid[1][1] + grid[2][0] != sum)
        {
            return false;
        }
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int result = 0;
        // for each 3x3 matrix, see if it is a magic square
        int row = grid.size();
        int col = grid[0].size();
        int rStart = 0;
        int cStart = 0;
        // while not out of bound
        while (!((rStart > row - 3) || (cStart > col - 3)))
        {
            vector<vector<int>> subGrid;
            for (int r = rStart; r < rStart + 3; ++r)
            {
                vector<int> currRow;
                for (int c = cStart; c < cStart + 3; ++c)
                {
                    currRow.push_back(grid[r][c]);
                }
                subGrid.push_back(currRow);
            }
            if (isMagic(subGrid))
            {
                result++;
            }
            if (cStart == col - 3)
            {
                rStart++;
                cStart = 0;
            }
            else
            {
                cStart++;
            }
        }
        return result;
    }
};