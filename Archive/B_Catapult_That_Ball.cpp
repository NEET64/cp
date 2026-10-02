#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    int q; cin >> q;

    vector<int> ar(n);
    for (int i = 0; i < n; i++) cin >> ar[i];

    int S = sqrt(n);
    vector<int> b(n, 0LL);

    for(int i=0; i<n; i++) {
        b[i/S] = max(b[i/S], ar[i]);
    }

    int ans=0;
    while(q--) {
        int l, r; cin >> l >> r;
        r-=2;
        int mx = -1LL;
        int ori = l-1;
        while(l<=r) {
            if(l%S==0 && l+S<=r) {
                mx = max(mx, b[l/S]);
                l+=S;
            }else {
                mx = max(mx, ar[l]);
                l++;
            }
        }

        ans += (mx <= ar[ori] || mx == -1LL);
    }
    cout << ans << "\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  

    int t; cin >> t;

    while (t--) solve();
}