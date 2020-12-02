#include <iostream>
#include <set>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

/*
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/08/02/ 00:00:12
*/

const int maxn = 1001;
int father[maxn], hobby[maxn];
int nums[maxn];

int findFather(int x) {
    int a = x;
    while (father[x] != -1) {
        x = father[x];
    }
    while (father[a] != -1) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b) {
    int faA = findFather(a), faB = findFather(b);
    if (faA != faB) {
        father[faA] = faB;
    }
}

int main()
{
    int N, cnt, n;
    scanf("%d", &N);
    memset(father, -1, sizeof(father));
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &cnt);
        getchar();getchar();
        while (cnt--) {
            scanf("%d", &n);
            if (hobby[n] == 0) {//之前无人拥有习惯n
                hobby[n] = i;
            }else
            Union(i, hobby[n]);
        }
    }
    for (int i = 1; i <= N; ++i) {
        ++nums[findFather(i)];
    }
    sort(nums, nums + N + 1, [](int &a, int &b) {return a > b;});
    int res = 0;
    for (int i = 0; i < N && nums[i]; ++i) ++res;
    printf("%d\n",res);
    for (int i = 0; i < res; ++i) {
        if (i) printf(" ");
        printf("%d", nums[i]);
    }
    return 0;
}