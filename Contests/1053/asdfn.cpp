    #include <bits/stdc++.h>
    using namespace std;

    int cal(vector<int>& p, vector<int>& a, int k) {
        int n = p.size();
        vector<int> prev(n);
        prev[0] = k;
        for(int i=1; i<n; i++) {
            prev[i] = prev[p[i]] - (prev[p[i]]/a[i]);
        }
        cout << "cal() R: ";
        for(int i=0;i<n;i++) cout << prev[i] << " ";
        cout << endl;
        return *min_element(prev.begin(), prev.end());
    }

    int check(vector<int>& p, vector<int>& a, int k, int test) {
        int n = p.size();
        vector<int> prev(n);
        vector<int> fault(n, 0); 
        prev[0] = k;
        int faulty = 0;
        for(int i=1; i<n; i++) {
            prev[i] = prev[p[i]] - (prev[p[i]]/a[i]);
            if(prev[i] < test) {
                fault[i] = 1;
                faulty++;
            }
        }

        cout << "check() test=" << test << " prev: ";
        for(int i=0;i<n;i++) cout << prev[i] << " ";
        cout << ", faulty nodes=" << faulty << endl;

        if(faulty==0) return *min_element(prev.begin(), prev.end());

        int lca = -1;
        for(int i=n-1; i>=0; i--) {
            fault[p[i]] += fault[i];
            if(fault[i] == faulty) {
                lca = i;
                break;
            }
        }

        cout << "check() LCA chosen: " << lca << endl;

        if(lca == 0 || lca == -1) return -1;

        a[lca] += (k+1);
        cout << "check() Added k+1 to a[" << lca << "] = " << a[lca] << endl;
        int ans = cal(p, a, k);
        a[lca] -= (k+1);

        cout << "check() ans=" << ans << " for test=" << test << endl;
        return (ans>=test)? ans: -1;
    }

    int main() {
        int t;
        cin >> t;
        while(t--) {
            int n, k;
            cin >> n >> k;
            vector<int> p(n);
            vector<int> a(n);
            for(int i=1; i<n; i++) {
                cin >> p[i]; p[i]--;
            }
            for(int i=1; i<n; i++) {
                cin >> a[i];
            }

            // int l=0, r=k;
            // while(l<r) {
            //     int mid = (r+l+1)/2;
            //     cout << "\nBinary search mid=" << mid << ", l=" << l << ", r=" << r << endl;
            //     int cur = check(p, a, k, mid);
            //     if(cur == -1) {
            //         r = mid-1;
            //     } else {
            //         l = mid;
            //     }
            // }
            // cout << l << endl;
            for(int i=cal(p, a, k); i<=k; i++) {
                cout << "checking " << i << endl;
                int cur = check(p, a, k, i);
                cout << "cur=" << cur << "\n\n";
            }
        }
    }
