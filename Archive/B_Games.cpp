#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    unordered_set<int> a;

    unordered_set<int> b;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if(a.count(x)) {
            a.erase(x);
        }else {
            b.insert(x);
        }
    }

    // for(int i: a) cout << i << " ";
    // cout << endl;
    // for(int i: b) cout << i << " ";
    // cout << endl;

    int mn = min(a.size(), b.size());

    if(a.size()>b.size()) {
        cout << mn*2+2 << "\n";
    }else {
        cout << mn*2+1 << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int t;
    cin >> t;

    while (t--) solve();
}