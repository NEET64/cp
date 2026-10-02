#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> ar(n);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    long long ans = 0LL;
    for(int i=1; i<n-1; i+=2) {
        ans += max(0LL, ar[i-1]-ar[i]);
        ar[i-1] = min(ar[i-1], ar[i]);
        long long sum = ar[i-1]+ar[i+1];
        if(sum<=ar[i]) {
            continue;
        }else {
            ans += sum - ar[i];
            ar[i+1] -= sum - ar[i];
        }
    }
    if(n%2==0) {
        ans+=max(0LL, ar[n-2]-ar[n-1]);
    } 
    // for(int i: ar) cout << i << " ";
    // cout<< endl;

    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int t;
    cin >> t;

    while (t--) solve();
}