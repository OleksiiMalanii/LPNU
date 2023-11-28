#include <iostream>
#include <limits>
using namespace std;
string res(long long a[]) {
    for (int i = 0; i < 5; ++i) {
        if (a[i] <= 0) {
            return "ERROR";
        }
    }
    long long MaxSide = LLONG_MAX;
    for (int i = 0; i < 5; ++i) {
        if (a[i] > MaxSide) {
            return "LOSS";
        }
        MaxSide = min(MaxSide, a[i]);
    }
    return "WIN";
}
int main() {
    long long a[5];
    for (int i = 0; i < 5; ++i) {
        cin >> a[i];
    }
    cout << res(a) << endl;
    return 0;
}
