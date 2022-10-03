#include <iostream>
#include <iomanip>

int pow2(int n) {
    return 1 << n;
}

int T1(int n) {
    if (n == 1)
        return 1;
    else
        return 2 * T1(n - 1) + 3;
}

int T2(int n) {
    return pow2(n + 1) - 3;
}

int main() {
    for (int i = 1; i < 21; i++) { 
        std::cout << std::setw(3) << i
                  << std::setw(10) << T1(i)
                  << std::setw(10) << T2(i)
                  << '\n';
    }
}

