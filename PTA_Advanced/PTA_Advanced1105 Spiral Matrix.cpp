#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *nums;
int idx = 0;
void solve(int *arr[], int i1, int j1, int i2, int j2) {
    for (int i = j1; i <= j2; ++i) {
        arr[i1][i] = nums[idx++];
    }
    for (int i = i1 + 1; i <= i2; ++i) {
        arr[i][j2] = nums[idx++];
    }
    if (i1 < i2) {
        for (int i = j2 - 1; i >= j1; --i) {
            arr[i2][i] = nums[idx++];
        }
    }
    if (j1 < j2) {
        for (int i = i2 - 1; i > i1; --i) {
            arr[i][j1] = nums[idx++];
        }
    }
}

int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main()
{
    int N;
    scanf("%d", &N);
    if (N == 0) {
        printf("\n");
        return 0;
    }
    int m = sqrt(1.0 * N), n = 0;
    for (int i = m; i <= N; ++i) {
        if (N % i == 0) {
            m = i;
            n = N / i;
            break;
        }
    }
    nums = (int *)malloc(sizeof(int) * N);
    if (m < n) {
        int tmp = m;
        m = n;
        n = tmp;
    }
    int **arr = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; ++i) {
        arr[i] = (int *)malloc(sizeof(int) * n);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &nums[i]);
    }
    qsort(nums, N, sizeof(int), cmp);
    for (int i = 0; i <= m / 2 && i <= n / 2; ++i) {
        solve(arr, i, i, m - i - 1, n - i - 1);
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", arr[i][j]);
            if (j < n - 1) {
                printf(" ");
            }            
        }
        printf("\n");
    }
    return 0;
}