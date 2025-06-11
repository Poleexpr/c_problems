#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;

  vector<int>vec(n);
  for(int i = 0; i < n; i++){
    cin >> vec[i];
  }
  int l = 0;
  int r = vec[n-1]-vec[0];

  while(l < r){
    int m = (l + r) /2;
    int cows = 1;
    int t = vec[0];

    for(int i = 0; i < n; i++){
      if(vec[i]-t > m){
        cows++;
        t = vec[i];
      }
    }
    
    if(cows >= k){
        l = m+1;
      
    } else {
      r = m;
    }
  }

    
    
  cout << l << endl;
    return 0;
}
