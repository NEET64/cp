#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> ar(m);
    int prev=0;
    bool fail = false;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        ar[i] = x;
        if(prev >= x) fail = true;
        prev = x;
    }

    if(fail || ar[m-1]>n) {
        cout << 1 << endl;
        return;
    }

    cout << n-ar[m-1]+1 << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int t;
    cin >> t;

    while (t--) solve();
}