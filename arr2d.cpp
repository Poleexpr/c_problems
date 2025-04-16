#include <iostream>
using namespace std;

void show2dArr(){
  int m2d[2][3] = { {1, 2, 3}, {4, 5, 6} };
  
  for( int i = 0; i != 2; ++i ) {
    for( int j = 0; j != 3; ++j ){
      cout << m2d[i][j] << " ";
    }
    cout << endl;
  }
}

int ** create_array2d(size_t a, size_t b) {
  int ** m = new int *[a];
  for (size_t i = 0; i != a; ++i){
    m[i] = new int[b];
  }
  return m;
  }

void free_array2d(int ** m, size_t a, size_t b) {
  for (size_t i = 0; i != a; ++i){
    delete [] m[i];
  }
  delete [] m;
}

void findMin(int *m[], unsigned rows, unsigned cols){
  int min = m[0][0];
  int targetRow = 0;
  
  for( int i = 0; i != rows; ++i ) {
    for( int j = 0; j != cols; ++j ){
      if(min > m[i][j]){
        min = m[i][j];
        targetRow = i;
      }
    }
  }

  int *t = m[targetRow];
  m[targetRow] = m[0];
  m[0] = t;

  cout << targetRow << endl;
}

int main(){
  int ** m = create_array2d(2,3);

  findMin(m, 2, 3);

  free_array2d(m, 2, 3);

  return 0;
}