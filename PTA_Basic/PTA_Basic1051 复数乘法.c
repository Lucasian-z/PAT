#include <stdio.h>
#include <math.h>

int main()
{
    double r1, p1, r2, p2;
    int ret = scanf("%lf %lf %lf %lf", &r1, &p1, &r2, &p2);
    if (ret != 4)
        return 0;
    double A, B, tmp = r1;
    r1 = tmp * cos(p1);
    p1 = tmp * sin(p1);
    tmp = r2;
    r2 = tmp * cos(p2);
    p2 = tmp * sin(p2);
    A = r1 * r2 - p1 * p2;
    if(fabs(A) <= 0.01)
        A = 0;
    printf("%.2f", A);
    B = p1 * r2 + r1 * p2;
    if (fabs(B) <= 0.01)
        B = 0;
    if(B >= 0)
        printf("+");
    printf("%.2fi", B);

    return 0;
}