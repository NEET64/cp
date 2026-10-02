#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b, k;
    cin >> a >> b >> k;
    long long g = gcd(a,b);

    if(a/g<=k && b/g<=k) {
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