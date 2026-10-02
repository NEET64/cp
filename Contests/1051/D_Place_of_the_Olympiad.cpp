#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int s = (k+n-1)/n;

    int gap = m-s;

    // cout << s << " " << m << endl;

    cout << (m)/(gap+1) << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int t;
    cin >> t;

    while (t--) solve();
}