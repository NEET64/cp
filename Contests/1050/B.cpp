#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        int ans=0;
        cin >> n >> m >> x >> y;
        for(int i=0; i<n; i++) {
            int cur;
            cin >> cur;
            if(cur > 0 && cur < y) ans++;
        }
        for(int i=0; i<m; i++) {
            int cur;
            cin >> cur;
            if(cur > 0 && cur < x) ans++;
        }

        cout << ans << endl;
    }
    return 0;
}