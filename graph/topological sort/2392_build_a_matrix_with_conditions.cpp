#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    // true if cycle detected
    bool topologicalSortUtil(int v, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s, vector<bool> &recStack)
    {
        visited[v] = true;
        recStack[v] = true;

        for (auto i : adj[v])
        {
            if (!visited[i] && topologicalSortUtil(i, adj, visited, s, recStack))
            {
                return true;
            }
            else if (recStack[i])
            {
                return true;
            }
        }
        s.push(v);
        recStack[v] = false;
        return false;
    }

    vector<int> topologicalSort(vector<vector<int>> &adj, int k)
    {
        stack<int> s;
        vector<bool> visited(k, false);
        vector<bool> recStack(k, false);
        vector<int> result;

        for (int i = 0; i < k; ++i)
        {
            if (!visited[i])
            {
                if (topologicalSortUtil(i, adj, visited, s, recStack))
                {
                    return result;
                }
            }
        }

        while (!s.empty())
        {
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
    {
        vector<vector<int>> retval(k, vector<int>(k, 0));
        vector<vector<int>> empty_result;

        // topo sort on row
        vector<vector<int>> adj_row(k);
        for (auto i : rowConditions)
        {
            adj_row[i[0] - 1].push_back(i[1] - 1);
        }
        vector<int> sorted_row = topologicalSort(adj_row, k);
        if (sorted_row.empty())
        {
            return empty_result;
        }

        // topo sort on col
        vector<vector<int>> adj_col(k);
        for (auto i : colConditions)
        {
            adj_col[i[0] - 1].push_back(i[1] - 1);
        }
        vector<int> sorted_col = topologicalSort(adj_col, k);
        if (sorted_col.empty())
        {
            return empty_result;
        }

        for (int i = 0; i < k; ++i)
        {
            int num = sorted_row[i];
            for (int j = 0; j < k; ++j)
            {
                if (sorted_col[j] == num)
                {
                    retval[i][j] = num + 1;
                    break;
                }
            }
        }
        return retval;
    }
};