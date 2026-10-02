#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int n, vector<pair<int,int>> &edges) {
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);

    for (auto &e : edges) {
        int u = e.first, v = e.second;
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }
    return topo;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> edges;
    for (int i = 0; i < n-1; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        u--; v--; // shift to 0-based
        if (x > y) edges.push_back({u, v});
        else edges.push_back({v, u});
    }

    vector<int> topo = topoSort(n, edges);
    vector<int> ans(n);
    int val=n;
    for(int i=0; i<n; i++) {
        ans[topo[i]] = val--;
    }
    for (int i : ans) cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
