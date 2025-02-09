#include <iostream>
#include <cstdint>
using namespace std;

void wierd_algorithm(uint64_t n){
  while(n != 1){
    std::cout << n << " ";
    if(n % 2 == 0){
      n = n/2;
    } else {
      n = n * 3 + 1;
    }
  }
  std::cout << 1;
}

int main(){
  uint64_t n;
  cin >> n;

  wierd_algorithm(n);

  return 0;
}