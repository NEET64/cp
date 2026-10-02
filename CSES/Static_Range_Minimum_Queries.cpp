#include <bits/stdc++.h>
using namespace std;


// i is starting index and p is power of 2
// 1,2 -> 1 2 3 4 -> min( [1,2] , 3,4)
int sp(int i, int p, vector<vector<int>>& spt, vector<int>& ar) {
    if (p == 0) return spt[i][p] = ar[i];
    if (spt[i][p] != -1) return spt[i][p];

    return spt[i][p] = min(sp(i, p - 1, spt, ar), sp(i + (1 << (p - 1)), p - 1, spt, ar));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> ar(n);
    for (int i = 0; i < n; i++) cin >> ar[i];

    vector<vector<int>> spt(n, vector<int>(31, -1));
    for (int i = 0; i < n; i++) {
        for (int p = 0; (1 << p) <= n - i; p++) {
            spt[i][p] = sp(i, p, spt, ar);
        }
    }

    for (auto v : spt) {
        for (auto i : v) {
            if (i == -1) cout << ". ";
            else cout << i << " ";
        }
        cout << "\n";
    }
}


// this is sqrt decomposition
// int S = sqrt(n);
// vector<int> b(n);
// for(int i=0; i<n; i+=S) {
//     b[i/S] = *min_element(ar.begin() + i, ar.begin() + i + S);
// }

// while(q--) {
//     int l, r;
//     cin >> l >> r;
//     int m = INT_MAX;
//     for(int i=l-1; i<r;) {
//         if(i%S == 0 && i+S<r) {
//             m = min(m, b[i/S]);
//             i+=S;
//         }else {
//             m = min(m, ar[i]);
//             i++;
//         }
//     }
//     cout << m << "\n";
// }