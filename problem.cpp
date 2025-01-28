#include <iostream>
#include <ctime>
using namespace std;

static const int N = 1000;

int find(int n){
  for(int i = 2; i*i <= n; i++){
     if(n % i == 0) return i;
  }
return n;
}

int main(){
std::cout << find(5);
std::cout << find(6);
}
