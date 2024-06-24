#include <stdio.h>

void printPrimes(int n) {
    int primes[n + 1];
    for (int i = 0; i <= n; i++) {
        primes[i] = 1;
    }
    for (int p = 2; p * p <= n; p++) {
        if (primes[p] == 1) {
            for (int i = p * p; i <= n; i += p) {
                primes[i] = 0;
            }
        }
    }
    for (int p = 2; p <= n; p++) {
        if (primes[p] == 1) {
            printf("%d ", p);
        }
    }
}

int main() {
    int n;
    printf("Enter the limit: ");
    scanf("%d", &n);
    printf("Prime numbers up to %d are: ", n);
    printPrimes(n);
    return 0;
}
