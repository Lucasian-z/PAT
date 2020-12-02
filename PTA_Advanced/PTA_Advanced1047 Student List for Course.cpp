#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

char name[40000][5];
vector<int> course[2501];
int idx = 0;
bool cmp(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    if (N == 0) {
        for (int i = 1; i <= K; ++i) {
            printf("%d 0\n", i);
        }
        return 0;
    }
    int cnt, num;
    while (N--) {
        scanf("%s %d", name[idx], &cnt);
        while (cnt--) {
            scanf("%d", &num);
            course[num].push_back(idx);
        }
        ++idx;
    }
    for (int i = 1; i <= K; ++i) {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp);
        for (int j = 0; j < course[i].size(); ++j) {
            printf("%s\n", name[course[i][j]]);
        }
    }
    return 0;
}