#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    if(k>=(max(a,b)) || gcd(a,b)>1) {
        cout << "1" << endl;
    }else{
        cout << "2" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int t;
    cin >> t;

    while (t--) solve();
}