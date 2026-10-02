#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> ar(n);
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    ans.push_back(1);
    int cur = 2;
    for (int i = 1; i < n; i++) {
        int dif = ar[i] - ar[i - 1];
        if (dif == i + 1) {
            ans.push_back(cur);
            cur++;
        }
        else {
            ans.push_back(ans[ans.size() - dif]);
        }
    }


    for (int i : ans) cout << i << " ";


    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}
