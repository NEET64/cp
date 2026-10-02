#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    if(a[n-1]!=b[n-1]) {
        cout << "NO" << endl;
        return;
    }
    for(int i=n-2; i>=0; i--) {
        if(a[i]!=b[i] && !((a[i]^a[i+1])==b[i] || (a[i]^b[i+1])==b[i])) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout << "YES" << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int t;
    cin >> t;

    while (t--) solve();
}