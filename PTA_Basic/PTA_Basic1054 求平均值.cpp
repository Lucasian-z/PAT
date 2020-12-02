#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    char a[50], b[50];
    double sum = 0.0, data = 0.0;
    int cnt = 0, N = 0, flag = 0;
    cin >> N;
    while (N--)
    {
        flag = 0;
        scanf("%s", a);
        sscanf(a, "%lf", &data);
        sprintf(b, "%.2lf", data);
        for(int i = 0; i < strlen(a); ++i)
        {
            if(a[i] != b[i])
                flag = 1;
        }
        if(flag == 1 || data < -1000 || data > 1000)
            printf("ERROR: %s is not a legal number\n", a);
        else{
            ++cnt;
            sum += data;
        }
    }
    if(cnt > 1)
    {
        printf("The average of %d numbers is %.2f\n", cnt, sum/cnt);
    }
    else if(cnt == 1)
        printf("The average of 1 number is %.2f\n", sum);
    else
        printf("The average of 0 number is Undefined\n");
    return 0;
}
