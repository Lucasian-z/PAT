#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int N, K, cnt;
    scanf("%d", &N);
    vector<set<int>> ivec(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &cnt);
        while (cnt--) {
            scanf("%d", &K);
            ivec[i].insert(K);
        }
    }
    scanf("%d", &K);
    while (K--) {
        scanf("%d%d", &N, &cnt);
        int n = 0;
        for (auto &item : ivec[N-1]) {
            if (ivec[cnt-1].find(item) != ivec[cnt-1].end()) {
                ++n;
            }
        }
        printf("%.1f\%\n", (double)n / (ivec[cnt-1].size() + ivec[N-1].size() - n) * 100);
    }
    return 0;
}