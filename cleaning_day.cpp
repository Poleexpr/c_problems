#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int  n, r, c;
  cin >> n >> r >> c;

  vector<int>vec(n);
  for(int i = 0; i < n; i++){
    cin >> vec[i];
  }

  sort(vec.begin(), vec.end());

  int l = 0;
  int ri = vec[n-1]-vec[0];

  while(l < ri){
    int m = (l+ri)/2;

    int j = 0;
    int k = 0;

    while((j+c-1) < n){
      if(vec[j+c-1] - vec[j] <= m){
        k++;
        j += c;
      } else {
        j++;
      }
    }

    if(k >= r){
      ri = m;
    } else{
      l = m + 1;
    }
  }
  cout << ri; 
  return 0;
}