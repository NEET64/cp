#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    long long int mod = 998244353;

    while (t--) {
        int n;
        cin >> n;
        long long int a[n];
        long long int b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        long long int ans = 2;
        for(int i=1; i<n; i++) {
            if(a[i]>=a[i-1] && a[i]>=b[i-1] && b[i]>=a[i-1] && b[i]>=b[i-1]) {
                ans = (ans<<1)%mod;
            }
        }

        
        cout << ans << endl;
    }
}