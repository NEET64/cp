#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int ar[n];
        bool check[n+1]={false};
        for (int i = 0; i < n; i++) {
            int cur;
            cin >> cur;
            ar[i] = cur;
            check[cur] = true;
        }
        int zct = count(ar, ar + n, 0);
        int l=n;
        int r=-1;
        bool add = true;
        if(zct == 1) {
            for(int i=0; i<n; i++) {
                if(ar[i] == 0) {
                    if(!check[i+1]) add = false;
                    break;
                }
            }
        }
        for(int i=0; i<n; i++) {
            if((add && ar[i]==0) || (ar[i]!=0 && ar[i]!=i+1)) {
                l = min(l, i+1);
                r = max(r, i+1);
            }
        }
        if(l==r || r==-1) cout << 0 << endl;
        else cout << r-l+1 << endl;
    }
}