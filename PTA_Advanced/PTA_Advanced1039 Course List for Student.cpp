#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
vector<set<int>> ivec(460005);

int func(char name[]) {
    int res = 0;
    for (int i = 0; i < 3; ++i) {
        res = res * 26 + (name[i] - 'A');
    }
    res = res * 26 + (name[3] - '0');
    return res;
}
int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    char name[5];
    int n1, n2, idx;
    while (K--) {
        scanf("%d%d", &n1, &n2);
        while (n2--) {
            scanf("%s", name);
            idx = func(name);
            ivec[idx].insert(n1);
        }
    }
    while (N--) {
        scanf("%s", name);
        idx = func(name);
        printf("%s ", name);
        printf("%d", ivec[idx].size());
        for (auto &item : ivec[idx]) {
            printf(" %d", item);
        }
        printf("\n");
    }
    return 0;
}