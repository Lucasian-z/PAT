#include <stdio.h>
#include <stdlib.h>
int main()
{
    int N, id, score;
    int maxi, max = 0;
    int ret = scanf("%d", &N);
    if(ret != 1)
        return 0;
    int *scores = (int *)calloc(N, sizeof(int));
    while (N--)
    {
        int ret = scanf("%d %d", &id, &score);
        if(ret != 2)
            return 0;
        scores[id] += score;
        if(max < scores[id])
        {
            max = scores[id];
            maxi = id;
        }
    }
    printf("%d %d", maxi, max);
    return 0;
}