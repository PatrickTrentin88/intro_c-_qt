#include <iostream>
#include <gmpxx.h>

mpz_class factorial(mpz_class n) {
    mpz_class ans = 1;
    for (mpz_class i = 2; i <= n; ++i) {
        ans = ans * i;
    }
    return ans;
}

int main() {
    std::cout << "Please enter n: " << std::flush;
    mpz_class n;
    std::cin >> n;

    if (cmp(n, 0) >= 0) {
        mpz_class nfact = factorial(n);
        std::cout << "factorial(" << n
                  << ") = " << nfact
                  << std::endl;
    } else {
        std::cerr << "Undefined: "
                  << "factorial of a negative number: "
                  << n << std::endl;
    }
}
