#include <bits/stdc++.h>
using namespace std;

void insert(deque<int> &q, int x) {
    while(!q.empty() && q.back() > x) {
        q.pop_back();
    }
    q.push_back(x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  


    int n, k;
    int x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;
    vector<int> ar(n);
    ar[0] = x;
    for(int i=1; i<n; i++) {
        ar[i] = (a*1LL*ar[i-1] + b) % c;
    }

    deque<int> q;
    for(int i=0; i<k; i++) {
        insert(q, ar[i]);
    }
    int ans = q.front();

    for (int i = k; i < n; i++) {
        insert(q, ar[i]);
        if(q.front() == ar[i-k]) {
            q.pop_front();
        }

        ans ^= q.front();
    }


    cout << ans << endl;
}