#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> c(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[a[i]]++;
    }

    int x = 0, y = 0, z = 0;
    for (int i = 1; i <= n; i++) {
        if (c[i] == 0) {
            x = i;
            break;
        }
    }

    if (x == 0) {
        x = a[0], y = a[1], z = a[2];
    }
    else {
        z = a[n - 1];
        for (int i = 1; i <= n; i++) if (i != x && i != z) {
            y = i; break;
        }
    }

    for (int i = 0; i < k; i++) {
        if (i % 3 == 0) cout << x << " ";
        else if (i % 3 == 1) cout << y << " ";
        else cout << z << " ";
    }


    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
