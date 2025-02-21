#include <iostream>
#include <cmath>
using namespace std;

int sumNumbers (int n){
  int d = 0;
  int sum = 0;

  while(n != 0){
    d = n % 10;
    sum += d;
    n /= 10;
  }

  return sum;
}

int exchangeNumbers (int n){
  int newN = n;
  int f = n;
  int l = n % 10;

  int count = 0;

  while(f >= 10){
    f /= 10;
    count++;
  }

  newN -= l;
  newN -= f * pow(10, count);
  newN += l * pow(10, count);
  newN += f;

  return newN;
}

int findMaxNumber (int n){
  int i = 0;

  while (n != 0){
    if(n % 16 > i){
      i = n % 16;
    }
    n /= 16;
  }

  return i;
}

int hex(int n){
  int i = findMaxNumber(n);

  if(i >= 0 && i <= 9){
    return n * 2;
  } else if(i == 10 || i == 13){
    return n / 10;
  } else if(i == 11 || i == 12){
    return exchangeNumbers(n);
  } else if(i == 14){
    return n + 1l;
  } else {
    return n + sumNumbers(n);
  }
}

int main(){
  int n;
  cin >> n;
  cout << hex(n) << endl;

  return 0;
}