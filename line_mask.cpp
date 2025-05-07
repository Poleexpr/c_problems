#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool check(vector<int> row, string mask) {
  for (size_t i = 0; i < row.size(); i++) {
      if (mask[i] == '+' && row[i] <= 0){
          return false;
      }
      
      if (mask[i] == '-' && row[i] >= 0) {
          return false;
      }
      
      if (mask[i] == '.' && row[i] != 0) {
          return false;
      }
  }
  return true;
}


int main(){
  int n, m;
  cin >> n >> m;

  string mask;
  cin >> mask;

  vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
          cin >> matrix[i][j];
      }
    }

  int count = 0;

  for (const auto& row : matrix) {
      if (check(row, mask)) {
          count++;
      }
  }

  if (count > 0) {
      cout << count << endl;
  } else {
      cout << "No lines with mask" << endl;
  }
  
  return 0;
}