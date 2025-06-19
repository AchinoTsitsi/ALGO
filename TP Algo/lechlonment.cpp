#include <stdio.h>
#include <math.h>

double fonction(double x) {
    return x*x*x + x + 1;
}

double dichotomie(double (*f)(double), double a, double b, double p) {
    double c = (a + b) / 2.0;
    double fa = f(a);
    double fb = f(b);
    double fc = f(c);
    if (fabs(b - a) < p) {
        return c;
    }
    if (fa * fc < 0) {
        return dichotomie(f, a, c, p);
    } else {
        return dichotomie(f, c, b, p);
    }
}

int main() {
    double a = -3.0;
    double b = 3.0;

    printf("Entrez la précision (p) : ");
    double precision;
    scanf("%lf", &precision);

    double racine_approximative = dichotomie(fonction, a, b, precision);
    printf("Racine approximative : %lf\n", racine_approximative);

    return 0;
}

