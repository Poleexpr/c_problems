#include <iostream>
#include <vector>
using namespace std;

void factorization(int n){
  int d = 2;
  while(d*d <= n) {
    if (n%d==0) {
      std::cout << d << " ";
      n/= d;
    } else {
      d +=1;
    }
  } 
  if (n > 1){
    std::cout << n;
  }

}

int main(){
factorization(12);
}