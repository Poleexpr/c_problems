#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;

  vector<vector<int>> vec(n, vector<int>(m));
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> vec[i][j];
    }
  }

  vector<int> row_min_val(n, INT_MAX);
  vector<vector<int>> row_min_cols(n);
  for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vec[i][j] < row_min_val[i]) {
                row_min_val[i] = vec[i][j];
                row_min_cols[i].clear();
                row_min_cols[i].push_back(j);
            } else if (vec[i][j] == row_min_val[i]) {
                row_min_cols[i].push_back(j);
            }
        }
    }

    vector<int> col_max_val(m, INT_MIN);
    vector<vector<int>> col_max_rows(m);
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (vec[i][j] > col_max_val[j]) {
                col_max_val[j] = vec[i][j];
                col_max_rows[j].clear();
                col_max_rows[j].push_back(i);
            } else if (vec[i][j] == col_max_val[j]) {
                col_max_rows[j].push_back(i);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j : row_min_cols[i]) {
            for (int k : col_max_rows[j]) {
                if (k == i) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;
  

  return 0;
}