#include <bits/stdc++.h>
using namespace std;

struct splitmix64 {
    size_t operator()(uint64_t x) const noexcept {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        x = x ^ (x >> 31);
        return (size_t)x;
    }
};

long long mostK(vector<int>& ar, int k, int L, int R) {
    int n = ar.size();
    unordered_map<int, int> freq; 
    long long ans = 0;
    int l = 0;

    for(int r = 0; r < n; r++) {
        freq[ar[r]]++;
        while((int)freq.size() > k) {
            if(--freq[ar[l]] == 0) freq.erase(ar[l]);
            l++;
        }
        int len = r - l + 1;
        if (len >= L) {
            ans += max(min(len, R) - L + 1, 0);
        }
    }
    return ans;
}

void solve() {
    int n, k, l, r;
    cin >> n >> k >> l >> r;

    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    long long ans = mostK(ar, k, l, r) - mostK(ar, k-1, l, r);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
