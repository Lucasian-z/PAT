#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef struct frac {
    long long up,down;
}Frac;
int gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

void reduction(Frac &res) {
    if (res.down < 0) {
        res.up *= -1;
        res.down *= -1;
    }
    if (res.up == 0) {
        res.down = 1;
    }else {
        long long tmp = gcd(abs(res.up), abs(res.down));
        res.down /= tmp;
        res.up /= tmp;
    }
    
}
void show(Frac &a) {
    reduction(a);
    if (a.up < 0) {
        printf("(");
    }
    if (a.down == 1) {
        printf("%lld", a.up);
    }else if (abs(a.up) > a.down) {
        printf("%lld %lld/%lld", a.up / a.down, abs(a.up) % a.down, a.down);
    }else {
        printf("%lld/%lld", a.up, a.down);
    }
    if (a.up < 0) {
        printf(")");
    }
}

void add(Frac &a, Frac &b) {
    Frac res;
    res.up = a.up * b.down + a.down * b.up;
    res.down = a.down * b.down;
    
    reduction(res);
    show(a);
    printf(" + ");
    show(b);
    printf(" = ");
    show(res);
    printf("\n");
}
void sub(Frac &a, Frac &b) {
    Frac res;
    res.up = a.up * b.down - a.down * b.up;
    res.down = a.down * b.down;
    reduction(res);
    show(a);
    printf(" - ");
    show(b);
    printf(" = ");
    show(res);
    printf("\n");
}
void multi(Frac &a, Frac &b) {
    Frac res;
    res.up = a.up * b.up;
    res.down = a.down * b.down;
    reduction(res);
    show(a);
    printf(" * ");
    show(b);
    printf(" = ");
    show(res);
    printf("\n");
}
void div(Frac &a, Frac &b) {
    Frac res;
    res.up = a.up * b.down;
    res.down = a.down * b.up;
    reduction(res);
    show(a);
    printf(" / ");
    show(b);
    printf(" = ");
    //printf("res.up = %d\n", res.up);
    if (b.up == 0) {
        printf("Inf");
    }else {
        show(res);
    }
    
    printf("\n");
}



int main()
{
    Frac a, b;
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
    
    add(a, b);
    sub(a, b);
    multi(a, b);
    div(a, b);
    return 0;
}