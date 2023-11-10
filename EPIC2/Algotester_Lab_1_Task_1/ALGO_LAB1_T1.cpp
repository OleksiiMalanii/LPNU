#include <iostream>
using namespace std;
int main() {
    int h[4], d[4];
    for (int i = 0; i < 4; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> d[i];
    }
    int h_max, h_min, h_max_i, h_min_i;
    h_max = h_min = h[0];
    for (int i = 0; i < 4; ++i) {
        if (h[i] >= h_max){
            h_max = h[i];
            h_max_i = i;
        }
        if (h[i] <= h_min) {
            h_min = h[i];
            h_min_i = i;
        }
    }
    bool cond1 = true;
    for (int i = 0; i < 4; i++) {
        if (d[i] > h[i]) {
            cout << "ERROR" << endl;
            return 0;
        }
        h[i] -= d[i];
        if (i == h_max_i) {
            for (int j = 0; j < 4; ++j) {
                if (h[j] >= h_max) {
                    h_max = h[j];
                    h_max_i = j;
                }
            }
        }
        if (i == h_min_i) {
            for (int j = 0; j < 4; ++j) {
                if (h[j] <= h_min) {
                    h_min = h[j];
                    h_min_i = j;
                }
            }
        }
        if (h_max >= 2*h_min) cond1 = false;
    }
    bool cond2 = true;
    for (int i = 1; i < 4; i++)
        if (h[i]!=h[i-1]) cond2 = false;
    if (cond1 && cond2)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}