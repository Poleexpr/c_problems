#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int m, n;
  cin >> m >> n;

  vector<pair<int, int>> a(m);
  vector<pair<int, int>> b(n);

  for(int i = 0; i < m; i++){
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  for(int j = 0; j < n; j++){
    cin >> b[j].first;
    b[j].second = j + 1;
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int l = 1;
  int r = min(n/2,m);
  vector<int> max_found_deers;

  while(l <= r){
    int mid = l+(r-l)/2;

    int i = 0;
    int j = 0;
    int k = n - mid;

    vector<int> found_deers;

    while(i < m && j < mid && k < n){
      if(b[j].first < a[i].first && a[i].first < b[k].first){
        found_deers.push_back(a[i].second);
        j++;
        k++;
      } 
      i++;
    }

    if(found_deers.size() >= mid){
      max_found_deers = move(found_deers);
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

    cout << max_found_deers.size() << endl;
    
    for(int i = 0; i < max_found_deers.size(); i++) {
         cout << max_found_deers[i] << " " << b[i].second << " " << b[n - max_found_deers.size() + i].second << endl;
    }

  return 0;
}