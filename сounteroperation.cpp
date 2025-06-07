#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n, m;
  cin >> n;

  vector<int> vec(n);
  cin >> vec[0];
  int max = vec[0];
  int min = vec[0];

  for (int i = 1; i < n; i++) {
    cin >> vec[i];
    if(vec[i] > max){
      max = vec[i];
    } else if(vec[i] < min){
      min = vec[i];
    }
  }

  for (int i = 0; i < n; i++) {
    if(vec[i]== max){
      vec[i] = min;
    } 
  }

  for (int i = 0; i < n; i++) {
    cout << vec[i] << " ";
  }

  return 0;
}