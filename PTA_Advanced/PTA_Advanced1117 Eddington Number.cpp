#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
bool cmp(int &a, int &b) {
    return a > b;
}

int main()
{
    int N;
    scanf("%d", &N);
    vector<int> arr(N + 1);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr.begin() + 1, arr.end(), cmp);
    int i;
    for (i = 1; i <= N; ++i) {
        if (arr[i] <= i) {
            break;
        }
    }
    printf("%d\n", i-1);
    return 0;
}