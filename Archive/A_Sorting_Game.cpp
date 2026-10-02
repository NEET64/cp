#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int z = 0;

    for (char c : s) if (c == '0')z++;

    vector<int> ar;

    if (z == n or z == 0) cout << "Bob\n";
    else {
        for (int i = 0; i < z; i++) {
            if (s[i] == '1') ar.push_back(i);
        }
        if (ar.size() == 0) {
            cout << "Bob\n";
            return;
        }
        for (int i = z; i < n; i++) {
            if (s[i] == '0') ar.push_back(i);
        }



        cout << "Alice\n" << ar.size() << "\n";
        for (int i : ar) cout << i + 1 << " ";
        cout << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) solve();
}