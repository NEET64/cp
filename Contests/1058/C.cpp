#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isPalindrome(const string& s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    if (n % 2 == 0) return true;
    return (n % 2 == 1 && s[n / 2] == '0');
}

void solve() {
    int n;
    cin >> n;

    string bin = "";
    while (n > 0) {
        bin += (n % 2) + '0';
        n /= 2;
    }

    for (int i = 0; i < 30; i++) {
        if (isPalindrome(bin)) {
            cout << "YES\n";
            return;
        }
        bin += '0';
    }

    cout << "NO\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
