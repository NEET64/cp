#include <bits/stdc++.h>
using namespace std;
#define int long long

// const int LG = 20;

// int get(int l, int r, vector<vector<int>>& spt, bool mx) {
//     if (l == r) return spt[0][l];
//     int k = 0;
//     while (l + (1 << (k + 1)) <= r) k++;
//     if (mx)return max(spt[k][l], spt[k][r - (1 << k) + 1]);
//     else return min(spt[k][l], spt[k][r - (1 << k) + 1]);
// }

// int32_t main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int n;
//     cin >> n;

//     vector<vector<int>> sptA(LG, vector<int>(n, LLONG_MIN));    
//     vector<vector<int>> sptB(LG, vector<int>(n, LLONG_MAX));

//     for (int i = 0; i < n; i++) cin >> sptA[0][i];
//     for (int i = 0; i < n; i++) cin >> sptB[0][i];

//     for (int k = 1; k < LG; k++) {
//         for (int i = 0; i + (1 << k) <= n; i++) {
//             sptA[k][i] = max(sptA[k - 1][i], sptA[k - 1][i + (1 << (k - 1))]);
//             sptB[k][i] = min(sptB[k - 1][i], sptB[k - 1][i + (1 << (k - 1))]);
//         }
//     }

//     long long ans = 0LL;
//     for (int i = 0; i < n; i++) {
//         int l = -1;
//         int r = -1;

//         int low = i, high = n - 1;
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             int a = get(i   , mid, sptA, true);
//             int b = get(i   , mid, sptB, false);

//             if (a == b) {
//                 l = mid;
//                 high = mid - 1;
//             }
//             else if (a > b) {
//                 high = mid - 1;
//             }
//             else {
//                 low = mid + 1;
//             }
//         }


//         if (l == -1) continue;

//         low = i, high = n - 1;
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             int a = get(i, mid, sptA, true);
//             int b = get(i, mid, sptB, false);

//             if (a == b) {
//                 r = mid;
//                 low = mid + 1;
//             }
//             else if (a > b) {
//                 high = mid - 1;
//             }
//             else {
//                 low = mid + 1;
//             }
//         }
//         // cout << i << " " << l << " " << r << "\n";

//         ans += r - l + 1;
//     }


//     cout << ans << "\n";
// }

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    deque<int> mx, mn;
    int ans = 0;

    for (int l = 0, i = 0; i < n; i++) {
        while (!mx.empty() && a[mx.back()] <= a[i]) mx.pop_back();
        while (!mn.empty() && b[mn.back()] >= b[i]) mn.pop_back();
        mx.push_back(i);
        mn.push_back(i);

        while (l <= i and a[mx.front()] > b[mn.front()]) {
            if (mx.front() == l) mx.pop_front();
            if (mn.front() == l) mn.pop_front();
            l++;
        }

        if (!mx.empty() and !mn.empty() and a[mx.front()] == b[mn.front()]) ans += min(mx.front(), mn.front()) - l + 1;

    }
    cout << ans;
}