#include <iostream>

double power(double x, int n) {
    if (n == 0)
        return 1; // x^0 = 1
    else if (n < 0)
        return 1 / power(x, -n); // при отрицательных степенях
    else
        return x * power(x, n - 1); // рекурсия
}

int main() {
    double base = 4;
    int exponent = 6;
    std::cout << base << "^" << exponent << " = " << power(base, exponent) << std::endl;
    return 0;
}
