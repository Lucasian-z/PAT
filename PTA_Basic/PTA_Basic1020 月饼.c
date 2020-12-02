#include <stdio.h>
typedef struct
{
    double kind_storge;
    double sum_price;
    double price;
} MoonCake;
int main()
{
    int N, M; //种类数和需求量
    int res = scanf("%d %d", &N, &M);
    getchar();
    if (res != 2)
        return 0;
    if(N > 1000 || M > 500)
        return 0;
    int i = 0, j = 0;
    MoonCake mooncake[1000];
    for (; i < N; ++i)
    {
        res = scanf("%lf", &mooncake[i].kind_storge);
        if (res != 1)
            return 0;
    }
    getchar();
    for (i = 0; i < N; ++i)
    {
        res = scanf("%lf", &mooncake[i].sum_price);
        if (res != 1)
            return 0;
        mooncake[i].price = mooncake[i].sum_price / mooncake[i].kind_storge;
    }

    double max;
    int p;
    for (i = 0; i < N - 1; ++i)
    {
        p = i;
        max = mooncake[i].price;
        for (j = i + 1; j < N; ++j)
        {
            if (mooncake[j].price > max)
            {
                max = mooncake[j].price;
                p = j;
            }
        }
        MoonCake tmp = mooncake[i];
        mooncake[i] = mooncake[p];
        mooncake[p] = tmp;
    }
    double sum = 0;
    for (i = 0; i < N; ++i)
    {
        if (M > mooncake[i].kind_storge)
        {
            sum += mooncake[i].sum_price;
            M -= mooncake[i].kind_storge;
        }
        else
        {
            sum += M * mooncake[i].sum_price / mooncake[i].kind_storge;
            break;
        }
    }
    printf("%.2lf", sum);
    return 0;
}