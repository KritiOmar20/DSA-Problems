class Solution {
public:
    vector<int> parent, sz;
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return;
        if (sz[u] < sz[v])
            swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];
    }

    int minEdgesReq(int n, vector<vector<int>>& adj) {
        int m = adj.size();
        if (m < n - 1)
            return -1;
        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto &edge : adj)
            unite(edge[0], edge[1]);

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                components++;
        }
        return components - 1;
    }
};