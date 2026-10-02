#include <bits/stdc++.h>
using namespace std;

bool hasDecreasingTriplet(vector<int>& nums) {
    long long max1 = LLONG_MIN, max2 = LLONG_MIN;

    for (int x : nums) {
        if (x >= max1) {
            max1 = x;              
        } else if (x >= max2) {
            max2 = x;              
        } else {
            return true;           
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;

    long long ar[n];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int mod = 1000000007;
    long long ans = 1LL;

    for(int i=0; i<n; i++) {
        vector<int> nums;
        nums.push_back(ar[i]);

        for(int j=i+1; j<n; j++) {
            nums.push_back(ar[j]);
            if(hasDecreasingTriplet(nums)) {
                break;
            }
        }

        ans = (ans+(1LL<<(nums.size()-2))%mod)%mod;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
