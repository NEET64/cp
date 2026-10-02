#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n % 2 and s[0] != '?' and s[0] != 'a') {
        cout << "No\n";
        return;
    }

    for (int i = n % 2; i < n; i += 2) {
        if (s[i] == s[i + 1] and s[i] != '?') {
            cout << "No\n";
            return;
        }
    }


    cout << "Yes\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) solve();
}