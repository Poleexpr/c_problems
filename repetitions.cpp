#include <iostream>
using namespace std;

void repetitions(string DNA){
  int count1 = 1;
  int count2 = 1;
  for(int i = 1; i <= DNA.length(); i++){
    if(DNA[i] == DNA[i-1]){
      count1++; 
   } else {
      count2=max(count2,count1);
      count1 = 1;
   }
  }
  cout << count2 << endl;
}

int main(){
  string DNA;
  cin >> DNA;
  repetitions(DNA); 
}