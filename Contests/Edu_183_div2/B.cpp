#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int zero = 0, one = 0, two = 0;
    for (char c : s) {
        if (c == '0') zero++;
        else if (c == '1') one++;
        else two++;
    }

    string res(n, '+');

    for (int i = 0; i < zero && i < n; i++) res[i] = '-';

    for (int i = n - 1; i >= n - one && i >= 0; i--) res[i] = '-';

    int plusCount = count(res.begin(), res.end(), '+');

    if (two >= plusCount) {
        for (char& c : res) if (c == '+') c = '-';
    }
    else {
        int l = 0, r = n - 1;
        int remaining = two;

        while (remaining > 0 && l < n && r >= 0) {
            while (l < n && res[l] != '+') l++;
            while (r >= 0 && res[r] != '+') r--;
            if (l > r) break;

            if (l < n) res[l] = '?';
            if (r >= 0 && r != l) res[r] = '?';

            l++, r--;
            remaining--;
        }
    }

    cout << res << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
