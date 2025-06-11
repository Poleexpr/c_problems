#include <iostream>
#include <cmath>
using namespace std;

int main(){
  long long w,h,n;

  cin >> w >> h >> n;

  long long l=0;
  long long r=max(w, h) * n;

  while(l < r){
    long long m = (l+r)/2;

    if((m / w) * (m / h) >= n){
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << l << endl;
  
  return 0;
}

