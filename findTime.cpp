#include <iostream>
#include <cmath>
using namespace std;

int findTime(double v1, double a1, double v2, double a2, double s){
  double a = (a1+a2) / 2;
  double b = v1+v2;

  if(a == 0){
    int t = fabs(-s / b);
    return t;
  }
  
  double d = (b * b) + (4 * a * s); 
  
  if(d < 0){
    return -1;
  } else if (d == 0){
    int t = -b/(2*a);
    return t;
  } else {
    int t = (-b + sqrt(d))/(2*a);
    return t;
  }
  
}

int main() 
{
    double v1, a1, v2, a2, s;
    cin >> v1, a1, v2, a2, s;
    cout << findTime(v1, a1, v2, a2, s) << endl;
    return 0;
}