#include <iostream>
#include <vector>

using namespace std;

void checkZeros(vector<vector<int>> &matrix, int i, int j, int rows, int cols){
  if (i < 0 || j < 0 || i >= rows || j >= cols || matrix[i][j] != 0){
    return;
  }

  matrix[i][j] = -1;

  checkZeros(matrix, i + 1, j, rows, cols);
  checkZeros(matrix, i - 1, j, rows, cols);
  checkZeros(matrix, i, j + 1, rows, cols);
  checkZeros(matrix, i, j - 1, rows, cols);
  checkZeros(matrix, i + 1, j + 1, rows, cols);
  checkZeros(matrix, i + 1, j - 1, rows, cols);
  checkZeros(matrix, i - 1, j + 1, rows, cols);
  checkZeros(matrix, i - 1, j - 1, rows, cols);
}

int main(){
  int N;
  cin >> N;

  vector<vector<int>> matrix(N, vector<int>(N));

  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      cin >> matrix[i][j];
    }
  }

  int result = 0;

  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      if (matrix[i][j] == 0){
        result++;
        checkZeros(matrix, i, j, N, N);
      }
    }
  }

  cout << result << endl;

  return 0;
}