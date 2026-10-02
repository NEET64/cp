#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> ar(2*n);

    for(int i=0, val=n; i<n; i++, val--) {
        ar[i] = val;
    }
    ar[n] = n;
    for(int i=n+1, val=1; val<n; i++, val++) {
        ar[i] = val;
    }


    for(int i: ar) {
        cout << i << " ";
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
