#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int ans=0;
        int last=0;
        int lastpos=0;
        for(int i=0; i<n; i++) {
            int cur, pos;
            cin >> cur >> pos;

            if(pos != lastpos) {
                if((cur-last)%2!=0) ans+=cur-last;
                else ans+=cur-last-1;
            }else {
                if((cur-last)%2!=0) ans+=cur-last-1;
                else ans+=cur-last;
            }
            last = cur;
            lastpos = pos;
        }
        cout << ans+m-last << endl;
    }
    return 0;
}