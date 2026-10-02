#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            vector<int> v(k);
            for (int j = 0; j < k; j++) {
                cin >> v[j];
            }
            int asize = ans.size();
            bool small=false;
            for(int i=0; i<min(k, asize); i++) {
                if(v[i]<ans[i]) {
                    small = true;
                    break;
                }else if(v[i] > ans[i]) break;
            }
            if (small) {
                for (int i = 0; i < min(k, asize); i++) {
                    ans[i] = v[i];
                }
            }
            if(k>asize) {
                for(int i=asize; i<k; i++) {
                    ans.push_back(v[i]);
                }
            }
        }

        for (int i : ans) cout << i << " ";
        cout << endl;
    }
    return 0;
}
