#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    priority_queue<int> cost;
    for (int i = 0; i < n; i++) {
        int cur;
        cin >> cur;
        cost.push(cur);
    }

    priority_queue<int> discount;
    for (int i = 0; i < k; i++) {
        int cur;
        cin >> cur;
        discount.push(-cur);
    }

    long long int ans = 0;

    while(!discount.empty() && !cost.empty()) {
        long long int cur = -discount.top();
        discount.pop();

        for(int i=0; i<cur-1; i++) {
            ans += cost.top();
            cost.pop();
            if(cost.empty()) {
                break;
            }
        }
        if(!cost.empty()) cost.pop();
    }

    while(!cost.empty()) {
        ans += cost.top();
        cost.pop();
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
