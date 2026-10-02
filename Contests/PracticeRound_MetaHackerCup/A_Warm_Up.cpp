#include <bits/stdc++.h>
using namespace std;

void solve(int test) {
  int n;
  cin >> n;

  vector<vector<int>> cur(n, vector<int>(3));
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> cur[i][0];
    mp[cur[i][0]] = i + 1;
    cur[i][2] = i + 1;
  }

  for (int i = 0; i < n; i++) {
    cin >> cur[i][1];
  }
  sort(cur.begin(), cur.end());
  vector<pair<int, int>> ans;
  bool fail = false;
  for (int i = 0; i < n; i++) {
    if (cur[i][0] == cur[i][1]) continue;
    if (mp[cur[i][0]] == i + 1) mp.erase(cur[i][0]);
    if (cur[i][0] < cur[i][1] && mp.count(cur[i][1])) {
      ans.push_back({ mp[cur[i][1]], cur[i][2] });
    }
    else {
      fail = true;
      break;
    }
  }

  cout << "Case #" << test << ": ";
  if (fail) {
    cout << -1 << endl;
  }
  else {
    cout << ans.size() << endl;
    for (auto x : ans) {
      cout << x.first << " " << x.second << endl;
    }
  }

}

void main_() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  for (int i = 1; i <= t; i++) solve(i);
}


static void run_main() {
  main_();
  exit(0);
}
int main() {
  size_t stsize = 1024 * 1024 * 1024; // run with a 1 GiB stack
  char* stack, * send;
  stack = (char*)malloc(stsize);
  send = stack + stsize;
  send = (char*)((uintptr_t)send / 16 * 16);
  asm volatile(
    "mov %0, %%rsp\n"
    "call *%1\n"
    :
  : "r"(send), "r"(run_main));
  return 0;
}