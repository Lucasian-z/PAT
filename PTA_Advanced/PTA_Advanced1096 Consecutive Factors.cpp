#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    int factors[100], idx = 0;
    int len = 0, st = 0;
    int sq = sqrt(1.0 * N), tmp = 1;
    for (int i = 2; i <= sq; ++i) {
        tmp = 1;
        int j = i;
        for (; j <= sq; ++j) {
            tmp *= j;
            if (N % tmp != 0) {
                break;
            }
        }
        if (j - i > len) {
            len = j - i;
            st = i;
        }
    }
    if (st == 0) {
        printf("1\n%d\n", N);
    }else {
        printf("%d\n", len);
        for (int i = st; i < len + st; ++i) {
            printf("%d", i);
            if (i < len + st - 1) {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}