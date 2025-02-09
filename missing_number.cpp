#include <iostream>
using namespace std;

void missing_number(long long n){
  long long sum = 0;
  for(int i = 0; i < n-1; i++){
    long long x;
    cin >> x;
    sum += x;
  }
  cout << (n * (n+1))/2 - sum << endl;
}

int main(){
  long long n;
  cin >> n;

  missing_number(n);

  return 0;
}