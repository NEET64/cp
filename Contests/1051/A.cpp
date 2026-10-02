#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int ar[n];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    int l=0, r=n-1;
    int ct=1;
    while(l<r) {
        if(ar[l] == ct) {
            l++;
        }else if(ar[r] == ct) {
            r--;
        }else {
            cout << "No\n";
            return;
        }
        ct++;
    }

    cout << "Yes\n" ;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
