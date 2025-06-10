#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    int t;
    for (int i = 0; i < k; i++) {
        cin >> t;

        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (vec[mid] >= t) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int first_pos = left;

        left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (vec[mid] <= t) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        int last_pos = left;

        if (vec[first_pos] != t || vec[last_pos] != t) {
            cout << 0 << endl;
        } else {
            cout << first_pos + 1 << " " << last_pos + 1 << endl;
        }
    }

    return 0;
}