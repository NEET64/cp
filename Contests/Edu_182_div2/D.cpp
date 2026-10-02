#include <bits/stdc++.h>
using namespace std;

long long int cal(vector<int>& ar, int x, int y, unordered_map<int, int>& mp) {
    long long int sell = 0LL;
    long long int cost = 0LL;
    unordered_map<int, int> cur;
    for(auto &i: ar) {
        int after = (i+x-1)/x;
        // cout<<after<<" ";
        sell+=after;
        cur[after]++;
        if(mp[after]-cur[after]<0) {
            cost+=y;
        } 
    }
    // cout << cost;
    // cout << endl;
    return sell-cost;
}

int main() {
    int t;
    cin >> t;

    while (t--) {int n, y;
        cin >> n >> y;
        vector<int> ar(n);
        unordered_map<int, int> mp;
        int max_val = 0;
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
            mp[ar[i]]++;
            max_val = max(max_val, ar[i]);
        }
        
        int low = 2, high = max_val + 1;
        long long int max_cal = -1e18;
        
        while (low <= high) {
            int mid1 = low + (high - low) / 3;
            int mid2 = high - (high - low) / 3;

            long long int val1 = cal(ar, mid1, y, mp);
            long long int val2 = cal(ar, mid2, y, mp);
            
            max_cal = max({max_cal, val1, val2});

            if (val1 < val2) {
                low = mid1 + 1;
            } else {
                high = mid2 - 1;
            }
        }
        for(int i=2; i<=max_val; i++) {
            if(i>=100 && i<130)
            cout << i<<" "<<cal(ar, i, y, mp) << endl;
        }
    }
}