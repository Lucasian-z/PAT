#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    int *arr = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);
    for (int i = 1; i < N; ++i) {
        arr[i] += arr[i-1];
    }
    if (N & 1) {
        printf("1 %d\n", max(arr[N-1] - 2 * arr[N/2-1], arr[N-1] - 2 * arr[N/2]));
    }else {
        printf("0 %d\n", arr[N-1] - 2 * arr[N/2-1]);
    }
    return 0;
}