#include <iostream>

using namespace std;

int main(){
  int n, x, y;
  cin >> n >> x >> y;

  int l = 0;
  int r= max(x*(n-1),y*(n-1));

  while(l < r){
    int m = (l + r)/2;
    if(m/x + m/y < n){
      l = m + 1;
    } else{
      r = m;
    }
  }

  cout << r + 1 << endl; 
  return 0;
}