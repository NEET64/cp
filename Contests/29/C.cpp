#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    
    if(s[0] == '0') s[0] = 'b';
    if(n>1 && s[1] == '0' && s[0] == 'b') s[1] = 'b';
    for (int i = 2; i < n; i++) {
        if(s[i] == '0') {
            if(s[i-1] == '0' || s[i-1] == 'b' || s[i-1] == 'f') {
                s[i] = s[i-1] = 'b';
            }else if(s[i-2] == 'b') {
                s[i] = 'b';
            }else if(s[i-2] == '0')  {
                s[i] = s[i-2] = 'f';
            }
        } 
            
    }
    
    if(s[n-1] == '0') s[n-1] = 'b';
    
    // cout << s << endl;


    int count = 0;
    for (char c : s) {
        if (c == '0') count++;
    }
    if(count) cout << "No" << endl;
    else cout << "Yes" << endl;
    // cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
