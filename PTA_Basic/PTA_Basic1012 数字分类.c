#include <stdio.h>

int main()
{
    int n, N;
    int A[5] = {0};
    int B[5] = {0};
    int flag = 1;
    scanf("%d", &N);
    int i = 0;
    while(i < N)
    {  
        scanf("%d", &n);
        if(n % 10 == 0)
        {
            A[0] += n;
            ++B[0];
        }
            
        if(n % 5 == 1)
        {
            A[1] += flag*n;
            flag *= -1;
            ++B[1];
        }
        if(n % 5 == 2)
        {
            ++A[2];
            ++B[2];
        }
        if(n % 5 == 3)
        {
            A[3] += n;
            ++B[3];
        }
        if(n % 5 == 4)
        {
            ++B[4];
            if(A[4] < n)
                A[4] = n;
        }
        ++i;
    }
    getchar();
    for(i = 0; i < 3; ++i)
    {
        if(B[i])
            printf("%d ", A[i]);
        else
        {
            printf("N ");
        }
        
    }
    if(B[3])
        printf("%.1f ", (double)(1.0*A[3]/B[3]));
    else 
        printf("N ");
    if(B[4])
        printf("%d", A[4]);
    else 
        printf("N");
    return 0;
}