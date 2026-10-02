#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    sort(ar.begin(), ar.end());

    int mx = 0;
    for(int i=1; i<n; i+=2) {
        mx = max(mx, ar[i]-ar[i-1]);
    }

    cout << mx << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
