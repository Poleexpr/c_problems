#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rating (int n, int *arr){
  vector <int> advanced;
  vector <int> underachieving;

  for(int i = 0; i < n; i++){
    if(arr[i] >= 90){
      advanced.push_back(arr[i]);
    }

    if(arr[i] < 60){
      underachieving.push_back(arr[i]);
    }
  }

  if (advanced.empty() || underachieving.empty()) {
    cout << "Impossible" << endl;
}

  sort(begin(advanced), end(advanced), greater<int>());

  if(advanced.size() > 3){
    advanced.resize(3);
  }

  int group_size = underachieving.size() / advanced.size();
  int remainder = underachieving.size() % advanced.size();
  
  int start = 0;
  
  for (int i = 0; i < advanced.size(); i++) {
      int end = start + group_size + (i < remainder ? 1 : 0);

      if (start >= underachieving.size()) {
        break;
      }

      cout << advanced[i];
        for (int j = start; j < end; ++j) {
            std::cout << " " << underachieving[j];
        }
        cout << std::endl;
        start = end;
  }
}


int main(){
  int n1 = 20;
  int arr1[20] = {80, 64, 98, 84, 85, 87, 71, 82, 96, 24, 93, 82, 96, 75, 66, 78, 92, 79, 74, 51,};

  int n2 = 30;
  int arr2[30] = {84, 91, 88, 64, 57, 79, 81, 78, 95, 62, 86, 82, 68, 65, 69, 90, 81, 88, 83, 94, 60, 76, 88, 99, 63, 78, 62, 81, 95, 78};

  int n;
  cin >> n;

  int *arr = new int[n];

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  } 

  rating(n, arr);

  delete [] arr;

  return 0;
}