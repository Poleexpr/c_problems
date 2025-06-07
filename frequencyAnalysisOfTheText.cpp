#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
  ifstream input("input.txt");
  ofstream output("output.txt");

  int numberOfWords = 0;
  vector<char> chars;

  while(true){
    char ch;
    input >> ch;

    if(ch == "T"){
      numberOfWords++;
      while(ch != ' '){
        chars.append(ch);
      }
    }
  }

  input.close();
  output.close();

  return 0;
}