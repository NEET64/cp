#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int w, h, d, n;
    cin >> w >> h >> d >> n;

    int wp = __gcd(n, w);
    int a = n / wp;
    int hp = __gcd(a, h);
    int b = a / hp;
    int dp = __gcd(b, d);
    int c = b / dp;

    if (c != 1) cout << -1 << "\n";
    else cout << wp - 1 << " " << hp - 1 << " " << dp - 1 << "\n";

}