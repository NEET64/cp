#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> ar(n);
    for (int i = 0; i < n; i++) cin >> ar[i];

    int S = sqrt(n);
    vector<int> b(n, LLONG_MAX);

    for(int i=0; i<n; i++) {
        b[i/S] = min(b[i/S], ar[i]);
    }

    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        int mn=LLONG_MAX;
        while(l<=r) {
            if(l%S==0 && l+S<=r) {
                mn = min(mn, b[l/S]);
                l+=S;
            }else {
                mn = min(mn, ar[l]);
                l++;
            }
        }

        cout << mn << "\n";
    }


}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  

    int t; cin >> t;

    while (t--) solve();
}