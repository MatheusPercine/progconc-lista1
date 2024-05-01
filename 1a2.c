#include <stdio.h>
#include <math.h>

double calcular_pi(int n) {
    double pi = 0.0;
    double termo;

    for (int k = 0; k < n; k++) {
        termo = 1.0 / pow(16, k) * (
            4.0 / (8 * k + 1) -
            2.0 / (8 * k + 4) -
            1.0 / (8 * k + 5) -
            1.0 / (8 * k + 6)
        );
        pi += termo;
    }

    return pi;
}

int main() {
    int n;
    n = 5;

    double pi = calcular_pi(n);
    printf("%.16f\n", pi);

    return 0;
}
