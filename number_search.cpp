#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n, k;

  cin >> n >> k;

  vector<int> vec(n);
  for(int i = 0; i < n; i++){
    cin >> vec[i]; 
  }

  int t;
  for(int i = 0; i < k; i++){
    cin >> t; 

    int l = 0;
    int r = n - 1;
    bool found = false;

    while(l <= r){
    int m =(r+l)/2;
    if(t < vec[m]){
      r = m - 1;
    } else if(t > vec[m]){
      l = m + 1;
    } else if(t == vec[m]){
      found = true;
      break;
    } 
  }

  cout << (found ? "YES" : "NO") << endl;
  }

  return 0;
}
