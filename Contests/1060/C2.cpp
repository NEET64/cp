#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> primes;
vector<bool> is_prime;

void sieve(int n = 200000) {
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    for (int i = 2; i <= n; i++)
        if (is_prime[i]) primes.push_back(i);
}

vector<int> factorize(int x) {
    vector<int> f;
    for (int p : primes) {
        if (p * p > x) break;
        if (x % p == 0) {
            f.push_back(p);
            while (x % p == 0) x /= p;
        }
    }
    if (x > 1) f.push_back(x);
    return f;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    map<int, int> mp;
    int ans = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        int x = a[i];
        auto fac = factorize(x);
        for (int p : fac) {
            if (mp.count(p)) {
                cout << "0\n";
                return;
            }
        }
        for (int p : fac) mp[p] = min(mp[p], b[i]);
    }


    for (int i = 0; i < n; i++) {
        int x = a[i];
        auto fac = factorize(x + 1);
        for (int p : fac) {
            if (mp.count(p)) {
                ans = min(ans, mp[p] + b[i]);
            }
        }
    }

    cout << (ans == LLONG_MAX ? -1 : ans) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int t; cin >> t;
    while (t--) solve();
}
