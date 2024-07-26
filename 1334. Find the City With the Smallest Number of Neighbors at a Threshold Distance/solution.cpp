typedef pair<int, int> iPair;

class Solution
{
public:
    vector<int> shortestPath(int src, vector<list<iPair>> &adj, int n)
    {
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

        vector<int> dist(n, INT_MAX);

        pq.push(make_pair(0, src));
        dist[src] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            list<iPair>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = (*i).first;
                int weight = (*i).second;

                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        return dist;
    }

    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<list<iPair>> adj(n);
        for (auto e : edges)
        {
            adj[e[0]].push_back(make_pair(e[1], e[2]));
            adj[e[1]].push_back(make_pair(e[0], e[2]));
        }
        int min = INT_MAX;
        int retval = 0;
        for (int i = 0; i < n; ++i)
        {
            int num_city = 0;
            vector<int> dist = shortestPath(i, adj, n);
            for (auto d : dist)
            {
                if (d <= distanceThreshold)
                {
                    num_city++;
                }
            }
            if (num_city <= min)
            {
                min = num_city;
                retval = i;
            }
        }
        return retval;
    }
};