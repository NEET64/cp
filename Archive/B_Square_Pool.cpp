#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int dx, dy, x, y;
        cin >> dx >> dy >> x >> y;
        if(x == y && dx == dy) ans++;
        else if(x+y == s && dx != dy) ans++;
    }


    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int t;
    cin >> t;

    while (t--) solve();
}