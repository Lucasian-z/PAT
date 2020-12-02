#include <stdio.h>

void quickSort(int *a, int left, int right)
{
    int i = left, j = right;
    if (i >= j)
        return;
    int tmp = a[i];
    while (i < j)
    {
        while (i < j && a[j] >= tmp)
            --j;
        if (i < j)
            a[i] = a[j];
        while (i < j && a[i] <= tmp)
            ++i;
        if (i < j)
            a[j] = a[i];
        }
    a[i] = tmp;
    quickSort(a, left, i - 1);
    quickSort(a, i + 1, right);
}

int main()
{
    int N, p, i, j;
    int ret = scanf("%d %d", &N, &p);
    if (ret != 2)
        return 0;
    int arr[N];
    for (i = 0; i < N; ++i)
    {
        ret = scanf("%d", &arr[i]);
        if (ret != 1)
            return 0;
    }
    quickSort(arr, 0, N - 1);
    // for (i = 0; i < N; ++i)
    //     printf("%d ", arr[i]);
    int max = 0;
    for (i = 0; i < N; ++i)
    {
        long tmp = (long)arr[i] * p;
        for (j = i + max; j < N; ++j)
        {
            if (arr[j] > tmp)
                break;
            if (j - i + 1 > max)
                max = j - i + 1;
        }
    }
    printf("%d", max);
    return 0;
}