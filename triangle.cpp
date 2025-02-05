#include <iostream>
#include <cmath>
using namespace std;

float calculateDistance(float xa, float ya, float xb, float yb){
  float dx = xa - xb;
  float dy = ya - yb;

  return sqrt(dx * dx + dy * dy);
}

void calculatePerimeter(float xa, float ya, float xb, float yb, float xc, float yc){
    float side1 = calculateDistance(xa, ya, xb, yb);
    float side2 = calculateDistance(xb, yb, xc, yc);
    float side3 = calculateDistance(xc, yc, xa, ya);

    float perimeter = abs(side1 + side2 + side3);

    std::cout << perimeter << endl;
}

void calculateArea(float xa, float ya, float xb, float yb, float xc, float yc){
  float area = abs((xb - xa) * (yc - ya) - (xc - xa) * (yb - ya)) * 0.5;
  std::cout << area << endl;
}

int main(){
calculateArea(-1, -3, 3, 4, 5, -5);
calculatePerimeter(-1, -3, 3, 4, 5, -5);
}