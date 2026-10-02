#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, rk, ck, rd, cd;
    cin >> n >> rk >> ck >> rd >> cd;


    bool right = cd > ck;
    bool left = cd < ck;
    bool down = rd > rk;
    bool up = rd < rk;

    if (right && down) {
        cout << max(rd, cd) << endl;
    }
    else if (left && down) {
        cout << max(rd, n - cd) << endl;
    }
    else if (right && up) {
        cout << max(cd, n - rd) << endl;
    }
    else if (left && up) {
        cout << max(n - rd, n - cd) << endl;
    }
    else if (right) {
        cout << cd << endl;
    }
    else if (left) {
        cout << n - cd << endl;
    }
    else if (up) {
        cout << n - rd << endl;
    }
    else cout << rd << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}
