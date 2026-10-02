#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> ar(n);
    map<int, int> right;
    map<int, int> left;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        right[ar[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {

    }







    cout << "" << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}
