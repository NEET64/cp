#include <bits/stdc++.h>
using namespace std;

vector<int> build(int n) {
    if(n == 1) return {0};
    if(n == 2) return {1, 0};
    n--;
    vector<int> ans;

    int root = sqrt(n);
    if(root*root != n) root++;
    else {
        for(int i=n; i>=0; i--) {
            ans.push_back(i);
        }
        return ans;
    }
    
    int target = root*root;
    
    int st = target-n;
    
    vector<int> left = build(st);

    while(n>=st) left.push_back(n--);
    return left;
}

void solve() {
    int n;
    cin >> n;

    vector<int> ans = build(n);
    for(int i : ans) cout << i << " ";

    cout << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int t;
    cin >> t;

    while (t--) solve();
}