#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> ar(n);
    vector<int> sorted(n);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        sorted[i] = ar[i];
    }
    sort(sorted.begin(), sorted.end());
    int l = n-k;
    int r = k-1;

    if(l>r) {
        cout<<"YES"<<endl;
        return;
    }
    
    for(int i=l; i<=r; i++) {
        if(sorted[i]!=ar[i]) {
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int t;
    cin >> t;

    while (t--) solve();
}