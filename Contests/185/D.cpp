#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;

    int direct = 0;
    int direct2 = 0;
    int chance = 0;
    int gap = 0;

    int cur = 0;
    bool big = false;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'X') {
            cur += 10;
            big = true;
        }
        else if (s[i] == 'V') {
            cur += 5;
            big = true;
        }
        else if (s[i] == 'I') {
            cur += big ? -1 : 1;
            big = false;
        }
        else {
            gap++;
            if (big) {
                direct++;
                s[i] = '-';
            }
            big = false;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'I' and s[i + 1] == '?') {
            direct2++;
        }
        else if (s[i] == '?' and s[i + 1] == '?') {
            chance++;
        }
    }
    // cout << s << " " << cur << " \n";
    for (int i = 0; i < m; i++) {
        int cx, cv, ci;
        cin >> cx >> cv >> ci;
        int ans = cur;
        // cout << ans << " start\n";

        int curgap = gap;
        int direct1 = min({ direct, ci, gap });
        ci -= direct1;
        curgap -= direct1;
        ans -= direct1;

        // cout << ans << " direct\n";



        int bache1 = min(ci, curgap);
        ans += bache1;
        curgap -= bache1;
        // cout << ans << " bache1\n";


        int setIV = min({ cv, chance, curgap, bache1 });
        cv -= setIV;
        chance -= setIV;
        bache1 -= setIV;
        curgap -= setIV;
        ans -= setIV;
        ans += setIV * 4;

        // cout << ans << " iv\n";



        int setV = min({ cv, curgap });
        ans += setV * 5;
        curgap -= setV;
        // cout << ans << " v\n";


        int setIX = min({ cx, curgap, bache1, chance });
        cx -= setIX;
        curgap -= setIX;
        bache1 -= setIX;
        chance -= setIX;
        ans -= setIX;
        ans += setIX * 9;
        // cout << ans << " ix\n";


        int setX = min({ cx, curgap });
        cx -= setX;
        curgap -= setX;
        ans += setX * 10;

        // cout << ans << " x\n";


        cout << ans << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}
