#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<long long> ar(m);
    vector<vector<long long>> v;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        vector<long long> cur;
        for(int j=0; j<l; j++) {
            int x;
            cin >> x;
            if(x<=m) {
                cur.push_back(x-1);
                ar[x-1]++;
            }
        }
        v.push_back(cur);
    }
    long long zero = 0;

    for(int i: ar) {
        if(i == 0) zero++;
    }

    if(zero>0) {
        cout << "No" << endl;
        return;
    }

    int c=0;
    for(auto &x : v) {
        bool fail = false;
        for(int i: x) {
            if(ar[i] == 1) {
                fail = true;
                break;
            }
        }
        if(!fail) {
            c++;
        }
        if(c>1)  {
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
