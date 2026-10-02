#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int size = 2*n+1;

    pair<int, int> v[n];
    int mp[size];
    fill(mp, mp+size, 0);

    for(int i = 0; i < n; i++) {  
        int l, r;
        cin >> l >> r;
        if(l == r) {
            mp[l]++;
        }
        v[i] = {l, r};
    }
    int ar[size];
    for(int i=0; i<size; i++) {
        ar[i] = mp[i]>0;
    }

    for(int i=1; i<size; i++) {
        ar[i]+=ar[i-1];
    }

    for(auto &p: v) {
        if(p.first == p.second) {
            cout << (mp[p.first] == 1? 1: 0);
        }else {
            int dis = ar[p.second] - ar[p.first-1];
            if(p.second-p.first+1 > dis) cout<<1;
            else cout<<0;
        }
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int t;
    cin >> t;

    while (t--) solve();
}