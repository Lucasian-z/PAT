#include <stdio.h>

int main()
{
    char c;
    int cnt[26] = {0};
    while((c = getchar()) != '\n')
    {
        if(c >= 'A' && c <= 'Z')
        {
            ++cnt[c+32-'a'];
        }
        else if(c >= 'a' && c <= 'z')
            ++cnt[c-'a'];
    }
    int maxi = 25;
    for(int i = 25; i >= 0; --i)
    {
        if(cnt[maxi] <= cnt[i])
            maxi = i;
    }
    printf("%c %d", 'a'+maxi, cnt[maxi]);
    return 0;
}