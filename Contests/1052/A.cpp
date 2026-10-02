#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    int ans = 0;
    for(int i=1; i<=100; i++) {
        int cur=0;
        for(auto &x : mp) {
            if(x.second >= i) {
                cur += i;
            }
        }
        ans = max(ans, cur);
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
