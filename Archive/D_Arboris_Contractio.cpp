#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    set<pair<int, int>> edges;
    vector<int> indeg(n);

    for (int i = 0; i < n-1; i++) {
        int l, r;
        cin >> l >> r;

        indeg[l-1]++;
        indeg[r-1]++;
        edges.insert({l, r});
    }

    int mx=0;
    int root=-1;
    for(int i=0; i<n; i++) {
        if(indeg[i]>mx) {
            mx = indeg[i];
            root = i+1;
        }
    }

    int leaf=0;
    map<int, int> mp;
    for(auto x: edges) {
        if(indeg[x.first-1]==1) {
            leaf++;
            mp[x.second-1]++;
        }else if(indeg[x.second-1]==1) {
            leaf++;
            mp[x.first-1]++;
        }
    }
    mx=0;
    for(auto x: mp) {
        mx = max(mx, x.second);
    }
    cout << leaf-mx << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int t;
    cin >> t;

    while (t--) solve();
}