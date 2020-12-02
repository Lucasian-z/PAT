#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    vector<int> arr(100001, 0);
    int num;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &num);
        if (0 < num && num < 100001) {
            arr[num] = 1;
        }
    }
    for (int i = 1; i <= 100020; ++i) {
        if (arr[i] == 0) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}