#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }
for(int i = 0; i < k; i++) {
        int t;
        cin >> t;

        int l = 0;
        int r = n - 1;
        int closest = vec[0];

        while(l <= r) {
            int m = (l + r) / 2;
            
            if(abs(vec[m] - t) < abs(closest - t)) {
                closest = vec[m];
            }
            else if(abs(vec[m] - t) == abs(closest - t)) {
                closest = min(vec[m], closest);
            }

            if(vec[m] < t) {
                l = m + 1;
            }
            else if(vec[m] > t) {
                r = m - 1;
            }
            else {
 
                closest = vec[m];
                break;
            }
        }
        cout << closest << endl;
    }

    return 0;
}
