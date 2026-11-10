#include <iostream>
#include <cmath>

int main() {
    long long n;
    std::cout << "Enter a value for n: ";
    if (!(std::cin >> n)) {
        return 1;
    }

    long long i = 1;
    long long iterations = 0;

    while (i < n) {
        i *= 2;
        ++iterations;
    }

    std::cout << "Iterations: " << iterations << '\n';
    return 0;
}