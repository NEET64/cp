#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    int ar[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        mp[ar[i]]++;
    }

    int c=0;
    for(int i=0; i<k; i++) {
        if(mp.find(i) == mp.end()) {
            c++;
        }
    }
    if(mp.find(k) != mp.end()) {
        c+=max(mp[k]-c, 0);
    }

    cout << c << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
