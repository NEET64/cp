#include <bits/stdc++.h>
using namespace std;
#define int long long

long long pow9(int k) {
    long long res = 1;
    for (int i = 0; i < k; ++i) {
        res *= 9;
    }
    return res;
}

long long fn(long long n) {
    std::string s = std::to_string(n);
    int m = s.length();
    long long ans = 0;

    long long p = 9;
    for (int i = 1; i < m; i++) {
        ans += p;
        p *= 9;
    }

    long long p9Remaining = pow9(m - 1);

    for (int i = 0; i < m; i++) {
        int digit = s[i] - '0';

        if (digit == 0) {
            break;
        }

        int choices = digit - 1;

        ans += choices * p9Remaining;

        p9Remaining /= 9;

        if (i == m - 1) {
            ans += 1;
        }
    }

    return ans;
}

void solve(int n) {

    int fun_ans = fn(n);
    int ans = n;
    for (int i = 1; i <= n; i++) {
        int k = i;
        while (k > 0) {
            if (k % 10 == 0) ans--;
            break;
            k /= 10;
        }
    }

    if (fun_ans != ans) {
        cout << fun_ans << " " << ans << " " << n << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i < 1000000000; i++) solve(i);
}
