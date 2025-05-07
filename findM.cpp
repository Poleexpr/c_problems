#include <iostream>
#include <fstream>
using namespace std;

int findDividers (int n){
  int dividers = 2;

  for (int i = 2; i < n; i++){
    if(n % i == 0){
      dividers ++;
    }
  }

  return dividers;
}


int main(){
  ifstream input("input.txt");
  ofstream output("output.txt");

  int N;
  input >> N;

  int M = N;

  while(N != 2){
    if(findDividers(N) > findDividers(M)){
      M = N;
    }
    N--;
  }

  output << M << endl;
  output << findDividers(M) << endl;

  input.close();
  output.close();

  return 0;
}