#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    string s;
    cin >> n >> s;

    vector<long long> leftA(n, 0), rightA(n, 0), leftB(n, 0), rightB(n, 0);
    long long l = s[0] == 'a' ? 1 : 0;
    for (long long i = 1; i < n; i++) {
        leftA[i] = leftA[i - 1];
        if (s[i] == 'a') {
            leftA[i] += i - l;
            l++;
        }
    }
    long long r = s[n - 1] == 'a' ? n - 2 : n - 1;
    for (long long i = n - 2; i >= 0; i--) {
        rightA[i] = rightA[i + 1];
        if (s[i] == 'a') {
            rightA[i] += r - i;
            r--;
        }
    }
    l = s[0] == 'b' ? 1 : 0;
    for (long long i = 1; i < n; i++) {
        leftB[i] = leftB[i - 1];
        if (s[i] == 'b') {
            leftB[i] += i - l;
            l++;
        }
    }
    r = s[n - 1] == 'b' ? n - 2 : n - 1;
    for (long long i = n - 2; i >= 0; i--) {
        rightB[i] = rightB[i + 1];
        if (s[i] == 'b') {
            rightB[i] += r - i;
            r--;
        }
    }
    long long mn = LLONG_MAX;
    for (long long i = 0; i < n; i++) {
        mn = min(leftA[i] + rightA[i], mn);
        mn = min(leftB[i] + rightB[i], mn);
    }
    cout << mn << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--) solve();
}
