#include <stdio.h>
#include <stdlib.h>
typedef struct frac{
    int up, down;
}node;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
void reducion(node *frac) {
    if (frac->down < 0) {
        frac->up *= -1;
        frac->down *= -1;
    }
    if (frac->up == 0) {
        frac->down = 1;
        return;
    }
    int tmp = gcd(frac->up, frac->down);
    frac->up /= tmp;
    frac->down /= tmp;
}

void add(node *a, node *b) {
    a->up = a->up * b->down + a->down * b->up;
    a->down = a->down * b->down;
    reducion(a);
}

int main()
{
    int n;
    scanf("%d", &n);
    node *fracs = (node *)malloc(sizeof(node) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d/%d", &fracs[i].up, &fracs[i].down);
        //printf("%d/%d\n", fracs[i].up, fracs[i].down);
    }
    node res;
    res.up = 0;
    res.down = 1;
    for (int i = 0; i < n; ++i) {
        add(&res, &fracs[i]);
    }
    if (res.up < 0) {
        printf("-");
        res.up *= -1;
    }
    if (res.down == 1) {
        printf("%d\n", res.up / res.down);
    }else if (res.up > res.down) {
        printf("%d %d/%d\n", res.up / res.down, res.up % res.down, res.down);
    }else {
        printf("%d/%d\n", res.up, res.down);
    }
    return 0;
}