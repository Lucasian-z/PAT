#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 本题中取w[10010]记录每个（0-10010）硬币的价值兼体积；
// dp[110]代表背包在每一种体积（0-110）下能达到的最大容量；
// choice[10010][110]在背包体积为 j (0-110)的情况下是否选第 i (0-10010)个硬币。
bool cmp(int &a, int &b) {
    return a > b;
}

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    vector<int> coins(N, 0);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &coins[i]);
    }
    sort(coins.begin(), coins.end(), cmp);
    vector<vector<int>> choice(N+1, vector<int>(M+1));
    vector<int> dp(M + 1, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = M; j >= coins[i]; --j) {
            if (dp[j] <= dp[j-coins[i]] + coins[i]) {
                choice[i][j] = 1;
                dp[j] = dp[j-coins[i]] + coins[i];
            }
        }
    }
    if (dp[M] != M) {
        printf("No Solution\n");
    }else {
        vector<int> res;
        while (M) {
            while (choice[N][M] == 0) {
                --N;
            }
            res.push_back(coins[N]);
            M -= coins[N--];
        }
        for (int i = 0; i < res.size(); ++i) {
            if (i) printf(" ");
            printf("%d", res[i]);
        }
        printf("\n");
    }
    return 0;
}