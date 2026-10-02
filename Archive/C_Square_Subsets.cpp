#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    long long int ans = 1;
    bool fail = false;
    for(auto i: mp) {
        if(i.second % 2 == 1) {
            fail = true;
            break;
        }
        ans *= 1LL<<(i.second);
    }
    if(fail) cout << 0 << endl;
    else cout << ans-1 << endl;
}