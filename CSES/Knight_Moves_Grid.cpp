#include <bits/stdc++.h>
using namespace std;
#define int long long

void fn(int i, int j, vector<vector<int>>& mat, int n) {
  int topleft = i - 2 >= 0 && j - 1 >= 0 ? mat[i - 2][j - 1] : INT_MAX;
  int topright = i - 2 >= 0 && j + 1 < n ? mat[i - 2][j + 1] : INT_MAX;
  int lefttop = i - 1 >= 0 && j - 2 >= 0 ? mat[i - 1][j - 2] : INT_MAX;
  int leftbottom = i + 1 < n && j - 2 >= 0 ? mat[i + 1][j - 2] : INT_MAX;

  mat[i][j] = min(min(topleft, topright), min(lefttop, leftbottom)) + 1;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;


  if (n == 4) {
    cout << "0 3 2 5\n";
    cout << "3 4 1 2\n";
    cout << "2 1 4 3\n";
    cout << "5 2 3 2\n";
    return 0;
  }
  vector<vector<int>> mat(n, vector<int>(n, INT_MAX));

  vector<vector<int>> base = {
      {0, 3, 2, 3},
      {3, 4, 1, 2},
      {2, 1, 4, 3},
      {3, 2, 3, 2}
  };

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      mat[i][j] = base[i][j];
    }
  }

  for (int k = 4; k < n; k++) {
    for (int i = 0; i <= k; i++) {
      fn(i, k, mat, n);
    }
    for (int j = 0; j <= k; j++) {
      fn(k, j, mat, n);
    }
  }

  for (auto& row : mat) {
    for (auto cell : row) {
      cout << cell << " ";
    }
    cout << "\n";
  }

}