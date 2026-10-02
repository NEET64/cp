#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) cin >> ar[i];

    unordered_map<int, deque<int>> mp;

    vector<int> dp(n, 0);

    if(ar[0] == 1) {
        dp[0] = 1;
    }else mp[ar[0]].push_back(0);

    for(int i=1; i<n; i++) {
        mp[ar[i]].push_back(i);
        int choose = -1;
        if (ar[i] <= mp[ar[i]].size()) {
            int front = mp[ar[i]].front();
            choose = (front>0 ? dp[front-1]: 0) + ar[i];
            mp[ar[i]].pop_front();
        }
        int not_choose = dp[i-1];

        dp[i] = max(choose, not_choose);
    }

    cout << dp[n-1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
