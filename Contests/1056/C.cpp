#include <bits/stdc++.h>
using namespace std;
#define int long long

int valid(vector<int>& a, int n) {
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        int prev = i;
        int right = a[0] - 1;

        bool fail = false;
        for (int i = 1; i < n; i++) {
            if (a[i] - 1 == prev + right) {
                prev++;
            }
            else if (a[i] - 1 == prev + right - 1) {
                right--;
            }
            else {
                fail = true;
                break;
            }
        }
        if (!fail && right == 0) ans++;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) cin >> ar[i];

    int ans = valid(ar, n);
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
