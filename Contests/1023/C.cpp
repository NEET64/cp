#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), c(m);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    for (int& x : c) cin >> x;

    sort(a.begin(), a.end());
    vector<pair<int, int>> mon;
    multiset<int> zero;
    for (int i = 0; i < m; i++) {
        if (c[i] > 0) mon.push_back({ b[i], c[i] });
        else zero.insert(b[i]);
    }
    sort(mon.begin(), mon.end());

    int idx = 0, ans = 0;
    priority_queue<pair<int, int>> pq;
    multiset<int> swords(a.begin(), a.end());

    while (!swords.empty()) {
        int x = *swords.begin();
        swords.erase(swords.begin());

        while (idx < mon.size() && mon[idx].first <= x) {
            pq.push({ mon[idx].second, mon[idx].first });
            idx++;
        }

        if (!pq.empty()) {
            int ci = pq.top().first; pq.pop();
            swords.insert(max(x, ci));
            ans++;
        }
        else {
            auto it = zero.upper_bound(x);
            if (it == zero.begin()) continue;
            --it;
            zero.erase(it);
            ans++;
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
