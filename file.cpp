#include <fstream>
#include <string>
using namespace std;

int main () {
   string data="Hello to everyone!";
   fstream file("test.dat", ios::out|ios::in|ios::trunc);
   file << data << endl;   
   file.seekg(6, ios::beg);
   string res;   
   file >> res;
   return 0;
}