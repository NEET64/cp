#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    if(x<y) cout << 2 << endl;
    else if(x-1 > y && y>1) cout << 3 << endl;
    else cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
