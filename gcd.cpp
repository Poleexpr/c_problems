#include <iostream>
#include <ctime>
using namespace std;

int findGCD(int a, int b){
  while( a != 0 && b != 0){
    if(a > b){
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

int findLCM(int a, int b){
  return (a * b) / findGCD(a, b);
}

int main(){
std::cout << findGCD(2, 2);
std::cout << findGCD(6, 9);
std::cout << findGCD(7, 2);

std::cout << findLCM(2, 2);
std::cout << findLCM(6, 9);
std::cout << findLCM(7, 2);
}