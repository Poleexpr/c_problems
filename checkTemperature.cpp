#include <iostream>
using namespace std;

int findMinDiff (int n, int *arr){
  int d = 1000;
  int k; 

  for (int i = 0; i < n * 2; i++){
    if(i % 2 == 1 && arr[i-1] - arr[i] < d) {
      d = arr[i-1] - arr[i];
      k = (i+1) / 2;
    }
  }
  
  return k;
}

void checkTemperature (int n, int *arr){
  int count = 0;

  for (int i = 0; i < n * 2; i++){
    if(i % 2 == 0 && arr[i] > 0){
      count++;
    }
  }

  cout << findMinDiff(n, arr) << endl;
  
  if(count == 0){
    cout << "No positive data";
  } else if (count == n){
    cout << "All data are positive";
  } else {
    int *newArr = new int[count];

    for (int i = 0; i < n * 2; i++){
      if(i % 2 == 0 && arr[i] > 0){
        newArr[i] = arr[i];
        cout << newArr[i] << " ";
      }
    }

    delete[] newArr;
  } 
}

int main(){
  int n;
  cin >> n;
  
  int *temperatures = new int[n * 2];

  for (int i = 0; i < n * 2; i++) {
    cin >> temperatures[i];
  }

  int a[28] = {26, 21, 22, 19, 25, 22, 23, 21, 22, 21, 19, 17, 19, 19, 17, 19, 24, 22, 25, 23, 28, 21, 27, 23, 24, 19, 25, 21};
  int ar[18] = {-11, -11, -6, -11, -10, -10, -9, -10, -7, -10, -6, -9, -3, -6, -2, -4, -3, -6};
  int arr[14] = {6, 5, -1, -2, 1, -1, 2, 2, 6, 5, 4, 2, -1, -3};

  checkTemperature(7, arr);
  // checkTemperature(9, ar);
  // checkTemperature(7, arr);

  delete [] temperatures;

  return 0;
}