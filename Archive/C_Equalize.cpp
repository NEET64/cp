#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n;
    string a, b;
    cin >> n >> a >> b;

    vector<bool> ar(n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ar[i] = a[i] != b[i];
        ans += a[i] != b[i];
    }

    for (int i = 1; i < n; i++) {
        if (ar[i] && ar[i - 1] && a[i] != a[i - 1]) {
            ans--;
            i++;
        }
    }


    cout << ans << "\n";

}