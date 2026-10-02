#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, x;
    cin >> n;

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    cin >> x;

    stack<int> st;
    st.push(ar[0]);
    for (int i = 1; i < n; i++) {
        bool change = false;
        int right = ar[i];
        while (!st.empty() && min(st.top(), right) <= x && max(st.top(), right) >= x) {
            st.pop();
            right = x;
        }
        st.push(right);
    }
    cout << (st.size() == 1 && st.top() == x ? "Yes" : "No") << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}
