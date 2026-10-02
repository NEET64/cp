#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int LG=20;
    int n;
    cin >> n;
    
    vector<vector<int>> spt(LG, vector<int>(n, -1));

    for (int i = 0; i < n; i++) cin >> spt[0][i];
    
    for(int k=1; k<=LG; k++) {
        for(int i=0; i+(1<<k)<=n; i++) {
            spt[k][i] = min(spt[k-1][i], spt[k-1][i+(1<<(k-1))]);
        }
    }
    
    int q; cin >> q;

    while(q--) {
        int32_t l, r;
        cin >> l >> r;
        int32_t m = r-l+1;

        int32_t k=0;
        while((1<<(k+1)) < m)k++;

        cout << min(spt[k][l], spt[k][r-(1<<k)+1]) << "\n";

    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  

    int t; cin >> t;

    while (t--) solve();
}