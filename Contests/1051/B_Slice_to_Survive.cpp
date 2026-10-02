#include <bits/stdc++.h>
using namespace std;

int count(int a, int b) {
    if(a==1 && b==1) return 0;
    if(a>b) return count((a+1)/2, b)+1;
    else return count(a, (b+1)/2)+1;
}

void solve() {
    int a, b, x, y;

    cin >> a >> b >> x >> y;

    int r = count(a, b-y+1);
    int s = count(a, y);
    int p = count(a-x+1, b);
    int q = count(x, b);

    // cout << a << " " << b-y+1 << endl;
    // cout << a << " " << y << endl;
    // cout << a-x+1 << " " << b << endl;
    // cout << x << " " << b << endl;
    // cout << endl;

    cout << min(min(p, q), min(r, s))+1 << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int t;
    cin >> t;

    while (t--) solve();

    cout << count(4, 8) ;
}