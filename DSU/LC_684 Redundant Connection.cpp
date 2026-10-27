
// TC-> O(nalpha(n)) , SC-> O(n)
class Solution
{
public:
    class DSU
    {
    public:
        vector<int> prnt, rank;
        DSU(int n)
        {
            prnt.resize(n + 1, 1);
            rank.resize(n + 1, 0);
            for (int i = 0; i <= n; i++)
                prnt[i] = i;
        }

        int find(int x)
        {
            if (x == prnt[x])
                return x;
            return prnt[x] = find(prnt[x]);
        }
        bool Union(int x, int y)
        {
            int a = find(x);
            int b = find(y);
            if (a == b)
                return false;
            if (rank[a] < rank[b])
                prnt[a] = b;
            else if (rank[b] < rank[a])
                prnt[b] = a;
            else
                prnt[b] = a, rank[a]++;
            return true;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        DSU dsu(n);
        for (auto &i : edges)
        {
            int u = i[0];
            int v = i[1];
            if (dsu.find(u) == dsu.find(v))
                return i;
            dsu.Union(u, v);
        }
        return {};
    }
};