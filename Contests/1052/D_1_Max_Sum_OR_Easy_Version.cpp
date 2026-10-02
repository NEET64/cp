#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long l, r;
    cin >> l >> r;

    vector<long long> ar(r+1);

    int width=0;
    while((r>>width) != 0) width++;

    for (int i = r; i > 0; i--) {
        if(ar[i] == 0) {
            while(width>0) {
                int target = (~i) & ((1LL<<width)-1);
                if(target<=r && ar[target]==0) {
                    ar[i] = target;
                    ar[target] = i;
                    break;
                }else {
                    width--;
                }
            }
        }
    }
    long long sum=0;
    for(int i=0; i<=r; i++) {
        sum += ar[i] | i;
    }


    cout << sum << endl;
    for (int i = 0; i <= r; i++) {
        cout << ar[i] << " ";
    }


    cout << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int t;
    cin >> t;

    while (t--) solve();
}