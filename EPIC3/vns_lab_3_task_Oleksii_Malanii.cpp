#include <iostream>
#include <cmath>
double f(double x) {
    return exp(x);
}
int factr(int n) {
    return (n == 0 || n == 1) ? 1 : n * factr(n - 1);
}
double powerSeriesExpansion(double x, int n) {
    double result = 0;
    for (int i = 0; i <= n; ++i) {
        result += pow(x, i) / factr(i);
    }
    return result;
}
int main() {
    const double a = 1.0;
    const double b = 2.0;
    const int k = 10;
    const double epsilon = 0.0001;
    for (double x = a; x <= b; x += (b - a) / k) {
        double exactResult = f(x);
        int n = 5;  
        double seriesResult = powerSeriesExpansion(x, n);

        std::cout << "x = " << x << "\tExact: " << exactResult << "\tSeries: " << seriesResult << std::endl;
    }
    return 0;
}
