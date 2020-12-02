#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 100

int main()
{
    char str1[N], str2[N], str3[N], str4[N];
    char *days[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%s", str3);
    scanf("%s", str4);
    int flag = 0;
    for (int i = 0; i < strlen(str1) && i < strlen(str2); ++i) {
        if (!flag && str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G') {
            printf("%s ", days[(str1[i] - 'A') % 7]);
            flag = 1;
        }else if(flag == 1 && str1[i] == str2[i]) {
            if (str1[i] >= '0' && str1[i] <= '9') {
                printf("%02d:", str1[i] - '0');
                break;
            }else if (str1[i] >= 'A' && str1[i] <= 'N') {
                printf("%d:", str1[i] - 'A' + 10);
                break;
            }
        }
    }    
    for (int i = 0; i < strlen(str3) && i < strlen(str4); ++i) {
        if (isalpha(str3[i]) && str3[i] == str4[i]) {
            printf("%02d\n", i);
            break;
        }
    }
    return 0;
}
