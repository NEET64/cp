#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    string s, t;
    cin >> n >> k >> s >> t;

    if (s == t) {
        cout << "0\n";
        return;
    }

    vector<string> ar;

    string ans = s;
    for (int i = 0; i < k; i++) {

        int down = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            while (s[j] == t[down] && down >= j) {
                if (j != down) {
                    ans[j + 1] = t[down];
                }
                down--;
            }
        }

        for (int i = down; i > 0; i--) {
            if (ans[i] != t[i]) ans[i] = ans[i - 1];
        }

        ar.push_back(ans);
        s = ans;
        if (ans == t) break;
    }

    if (ans == t) {
        cout << ar.size() << "\n";
        for (auto x : ar) cout << x << "\n";;
    }
    else cout << "-1\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}
