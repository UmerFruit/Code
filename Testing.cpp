#include "Headers.h"
double customLog10(double x) {
    if (x <= 0) {
        std::cerr << "Error: The number must be positive." << std::endl;
        return -1.0; // You can choose an appropriate error value here
    }

    double result = 0.0;
    while (x >= 10.0) {
        x /= 10.0;
        result += 1.0;
    }

    double fraction = x - 1.0;
    double fractionSum = 0.0;
    double denominator = 1.0;

    for (int i = 1; i <= 50; i++) {
        denominator *= i;
        fractionSum += pow(fraction, i) / denominator;
    }

    result += fractionSum;

    return result;
}

int main()
{
}