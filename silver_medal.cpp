#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n, m;
  cin >> n;

  int max = 0;
  int smax = 0;
  for (int i = 0; i < n; i++) {
    cin >> m;

    if(m > max){
      smax = max;
      max = m;
    } else if (m > smax && m != max) {
            smax = m;
        }
  }

  cout << smax << endl;
  return 0;
}