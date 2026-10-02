#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        unordered_map<int, int> mp;
        vector<int> v;
        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            mp[x]++;
            v.push_back(x);
        }
        bool fail = false;
        for(auto &p: mp) {
            if(p.second%k==0) {
                p.second/=k;
            }else {
                fail = true;
                break;
            }
        }
        if(fail) {
            cout << 0 << endl;
            continue;
        }
        long long int ans = 0LL;
        for(int l=0, i=0; i<n; i++) {
            while(mp[v[i]] == 0) {
                mp[v[l++]]++;
            }
            mp[v[i]]--;
            ans += i-l+1;
        }
        cout << ans << endl;
    }
    return 0;
}