#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int ar[n];
    int mi=INT_MAX;
    int left_small[n];
    int right_large[n];

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        mi = min(mi, ar[i]);
        left_small[i] = mi;
    }

    int ma=0;
    for (int i = n-1; i >= 0; i--) {
        ma = max(ma, ar[i]);
        right_large[i] = ma;
    }

    for (int i = 0; i < n; i++) {
        if(ar[i] == left_small[i] || ar[i] == right_large[i]) {
            cout << 1;
        }else cout << 0;
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int t;
    cin >> t;

    while (t--) solve();
}