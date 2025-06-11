#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
 
using namespace std;
 
vector<pair<double, double>> ods;
double v, d;
 
bool check(double t) {
  double p = 0;
  for (int i = 0; i < ods.size() - 1; i++) {
    t += (ods[i].first - p) / v;
    if (ods[i].second <= t) t += d;
    p = ods[i].first;
  }
  t += (ods.back().first - p) / v;
  return t >= ods.back().second;
}

int main() {
  cin >> v >> d;
  int n; cin >> n;
  ods.resize(n);
  for (int i = 0; i < n; i++) {
    double p; cin >> p;
    string s; cin >> s;
    ods[i] = {p, stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2))};
  }
  double l = 0, r = 24 * 60;
  for (int i = 0; i < 100; i++) {
    double mid = (l + r) / 2;
    if (check(mid)) r = mid;
    else l = mid;
  }
  int t = ceil(r + d * n + ods.back().first * 2 / v);
  int hours = (t / 60) % 24;
  int minutes = t % 60;
    
    cout << setw(2) << setfill('0') << hours << ":" 
         << setw(2) << setfill('0') << minutes << endl;
 
}