#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> odd;
        vector<int> even;

        cin >> n;
        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            if(x%2==0) even.push_back(x);
            else odd.push_back(x);
        }

        long long ans = 0;

        int ol = odd.size();
        if(ol>0) ans += accumulate(even.begin(), even.end(), 0LL);

        sort(odd.begin(), odd.end());
        for(int i=ol/2; i<ol; i++) {
            ans+=odd[i];
        }
        cout << ans << endl;
    }
    return 0;
}