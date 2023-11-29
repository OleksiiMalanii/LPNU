#include <iostream>
#include <limits>
using namespace std;
string res() {
    long long a[5];
    for (int i = 0; i < 5; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 5; ++i) {
        if (a[i] <= 0) {
            return "ERROR";
        }
    }
    for (int i = 1; i < 5; ++i) {
        if (a[i] > a[i-1]) {
            return "LOSS";
        }
    }
    return "WIN";
}
int main() {
    string result = res();
    cout << result << endl;
    exit(0);
}
