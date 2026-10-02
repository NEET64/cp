#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    string a, b;
    cin >> a >> b;

    vector<int> ar(26, 0);

    for (char c : a) ar[c - 'a']--;
    for (char c : b) ar[c - 'a']++;

    for (int i : ar) {
        if (i < 0) {
            cout << "Impossible" << endl;
            return;
        }
    }
    int p = 0;
    for (int i = 0; i < 26; i++) {
        if (p < a.size() and a[p] - 'a' <= i) {
            cout << a[p];
            p++;
            i--;
        }
        else {
            while (ar[i] > 0) {
                cout << char(i + 'a');
                ar[i]--;
            }
        }
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) solve();
}