#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> primes;
vector<bool> is_prime;

void sieve(int n) {
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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    set<int> seen;

    for (int x : a) {
        auto fac = factorize(x);
        for (int p : fac) {
            if (seen.count(p)) {
                cout << "0\n";
                return;
            }
        }
        for (int p : fac) seen.insert(p);
    }

    for (int x : a) {
        auto fac = factorize(x + 1);
        for (int p : fac) {
            if (seen.count(p)) {
                cout << "1\n";
                return;
            }
        }
    }

    cout << "2\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(200000);

    int t;
    cin >> t;
    while (t--) solve();
}
