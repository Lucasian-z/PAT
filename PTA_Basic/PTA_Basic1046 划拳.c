#include <stdio.h>

int main()
{
    int N, nums[4] = {0}, i, lose_cnt1 = 0, lose_cnt2 = 0;
    int ret = scanf("%d", &N);
    if(ret != 1)
        return 0;
    while(N--)
    {
        for(i = 0; i < 4;++i)
        {
            ret = scanf("%d", &nums[i]);
            if(ret != 1)
                return 0;
        }
        if(nums[1] == nums[0]+nums[2] && nums[3] != nums[0]+nums[2])
        {
            ++lose_cnt2;
        }
        else if(nums[1] != nums[0]+nums[2] && nums[3] == nums[0]+nums[2])
        {
            ++lose_cnt1;
        }
    }
    printf("%d %d", lose_cnt1, lose_cnt2);
    return 0;
}