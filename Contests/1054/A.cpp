#include <bits/stdc++.h>
#define int long long
using namespace std;

int main() {
    int n = 5;
    vector<int> v(n, 1); // here n is long long
    cout << v.size() << "\n";
}

using namespace std;

void solve() {
    int n;
    cin >> n;

    int z=0, m=0;

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        if(x==0) {
            z++;
        }else if(x == -1) m++;
    }

    if(m%2==1) {
        m = 2;
    }else m=0;

    cout << z+m << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
