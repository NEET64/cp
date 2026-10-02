#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        long long int cur;
        cin >> cur;
        cout << cur+(k*(cur%(k+1))) << " ";
    }

    cout << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int t;
    cin >> t;

    while (t--) solve();
}