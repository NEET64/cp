#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int ar[n];
    int ans=0;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        // cout << ans << " ";
    }

    cout << ar[0] + min(ar[1], ar[0]) << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int t;
    cin >> t;

    while (t--) solve();
}