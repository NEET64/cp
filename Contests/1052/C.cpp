#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int ans[n];

    for(int i=1; i<n-1; i++) {
        if(s[i] == '0' && s[i-1] == '1' && s[i+1] == '1') {
            cout << "No" << endl;
            return;
        }
    }
    if(s[0] == '0' && s[1] == '1') {
        cout << "No" << endl;
        return ;
    }

    if(s[n-1] == '0' && s[n-2] == '1') {
        cout << "No" << endl;
        return ;
    }

    for(int i=0; i<n; i++) {
        if(s[i] == '0') {
            ans[i] = 0;
        } else {
            ans[i] = i+1;
        }
    }

    for(int i=1; i<n; i++) {
        if(ans[i] == 0) ans[i] = ans[i-1];
    }
    int l=-1;
    for(int i=n-1; i>=0; i--) {
        if(ans[i]!=i+1) {
            if(l == -1) {
                l=ans[i]+1;
            }
            ans[i] = l;
            l++;
        }else {
            l = -1;
        }
    }
    cout << "Yes" << endl;
    for(int i: ans) {
        cout << i << " ";
    }
    cout <<  endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
