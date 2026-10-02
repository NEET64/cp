#include <bits/stdc++.h>
using namespace std;

void solve() {
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  


    int n, q;
    cin >> n >> q;

    vector<long long> ar(n);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    for(int i=1; i<n; i++) {
        ar[i]+=ar[i-1];
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << ar[r-1] - (l==1?0:ar[l-2]) << "\n";
    }
}