// main observation: increase step size every two directions
class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int r = rStart;
        int c = cStart;
        vector<vector<int>> result;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int currDir = 0;
        int numVisited = 0;
        int steps = 1;

        while (numVisited < rows * cols)
        {
            // Walk in current direction
            for (int i = 0; i < steps; i++)
            {
                if (r >= 0 && r < rows && c >= 0 && c < cols && !visited[r][c])
                {
                    vector<int> currCoor = {r, c};
                    result.push_back(currCoor);
                    visited[r][c] = true;
                    numVisited++;
                }

                // Move to the next cell
                r += dir[currDir].first;
                c += dir[currDir].second;
            }

            // Change direction
            currDir = (currDir + 1) % 4;

            // Increase steps every two directions (right and down, left and up)
            if (currDir == 0 || currDir == 2)
            {
                steps++;
            }
        }

        return result;
    }
};