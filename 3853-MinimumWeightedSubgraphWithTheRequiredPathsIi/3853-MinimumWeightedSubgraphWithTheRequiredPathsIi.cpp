// Last updated: 5/28/2025, 9:47:57 PM
class Solution {
public:
    vector<int> minimumWeight(vector<vector<int>>& edges,
                              vector<vector<int>>& queries) {
        int n = edges.size() + 1, LOG = 1;
        while ((1 << LOG) <= n)
            ++LOG;
        vector<vector<pair<int, int>>> g(n);
        for (auto& e : edges) {
            g[e[0]].emplace_back(e[1], e[2]);
            g[e[1]].emplace_back(e[0], e[2]);
        }
        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> depth(n);
        vector<long long> dist(n);
        function<void(int, int)> dfs = [&](int u, int p) {
            up[0][u] = p;
            for (auto& pr : g[u]) {
                int v = pr.first, w = pr.second;
                if (v == p)
                    continue;
                depth[v] = depth[u] + 1;
                dist[v] = dist[u] + w;
                dfs(v, u);
            }
        };
        dfs(0, 0);
        for (int k = 1; k < LOG; ++k)
            for (int i = 0; i < n; ++i)
                up[k][i] = up[k - 1][up[k - 1][i]];
        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v])
                swap(u, v);
            int diff = depth[u] - depth[v];
            for (int k = 0; k < LOG; ++k)
                if (diff & (1 << k))
                    u = up[k][u];
            if (u == v)
                return u;
            for (int k = LOG - 1; k >= 0; --k)
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            return up[0][u];
        };
        auto getDist = [&](int u, int v) {
            int w = lca(u, v);
            return dist[u] + dist[v] - 2 * dist[w];
        };
        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            long long d01 = getDist(q[0], q[1]);
            long long d02 = getDist(q[0], q[2]);
            long long d12 = getDist(q[1], q[2]);
            ans.push_back(int((d01 + d02 + d12) / 2));
        }
        return ans;
    }
};
