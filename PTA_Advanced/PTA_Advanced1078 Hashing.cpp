#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

bool isPrime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int M, N, num, tmp;
    scanf("%d%d", &M, &N);
    while (isPrime(M) == false) ++M;
    int *arr = (int *)malloc(sizeof(int) * M);
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < N; ++i) {
        scanf("%d", &num);
        tmp = num % M;
        
        if (i) printf(" ");
        if (arr[tmp] == 0) {//位置tmp未被占
            printf("%d", tmp);
            arr[tmp] = 1;
        }else {
            int gap = 1, flag = 0;
            while (gap < M / 2) {
                int n1 = (tmp + gap * gap) % M;
                if (arr[n1] == 0) {
                    printf("%d", n1);
                    arr[n1] = 1;
                    flag = 1;
                    break;
                }
                ++gap;
            }
            if (flag == 0) {
                printf("-");
            }
        }
    }
    return 0;
}