#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
  ifstream input("input.txt");
  ofstream output("output.txt");

  int N, M;
  input >> N >> M;

  vector<bool> zeros(N, false);
  vector<double> colsum(M, 0.0);

  while (true){
    int i;
    input >> i;
    if (i == -1)
      break;

    int ni;
    input >> ni;

    zeros[i] = true;

    for (int k = 0; k < ni; k++){
      double aij;
      int j;
      input >> aij >> j;
      colsum[j] += aij;
    }
  }

  for (int i = 0; i < N; i++){
    if (zeros[i] == false){
      output << i << " ";
    }
  }
  output << endl;

  int max = 0;
  for (int j = 1; j < M; j++){
    if (colsum[j] > colsum[max]){
      max = j;
    }
  }
  output << max << endl;

  input.close();
  output.close();

  return 0;
}