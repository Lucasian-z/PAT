#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

void downAdjust(vector<int> &arr, int low, int high) {
    int i = low, j = 2 * i + 1;
    while (j <= high) {
        if (j + 1 <= high && arr[j] < arr[j+1]) ++j;
        if (arr[i] < arr[j]) {
            swap(arr[i], arr[j]);
            i = j;
            j = 2 * i + 1;
        }else {
            break;
        }
    }
}


int main()
{
    int N;
    scanf("%d", &N);
    vector<int> originArr(N, 0);
    vector<int> sortedArr(N, 0);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &originArr[i]);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &sortedArr[i]);
    }
    int flag = 0, idx = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (sortedArr[i] > sortedArr[i+1]) {
            idx = i + 1;
            for (int j = i + 1; j < N; ++j) {
                if (sortedArr[j] != originArr[j]) {
                    printf("Heap Sort\n");
                    int i = N - 1;
                    while (sortedArr[i] > sortedArr[0]) {
                        --i;
                    }
                    swap(sortedArr[i], sortedArr[0]);
                    downAdjust(sortedArr, 0, i - 1);
                    flag = 1;
                    break;
                }
            }
            break;
        }
    }
    if (!flag) {
        printf("Insertion Sort\n");
        sort(sortedArr.begin(), sortedArr.begin() + idx + 1);
       
    }
    for (int i = 0; i < N; ++i) {
        if (i) printf(" ");
        printf("%d", sortedArr[i]);
    }
    return 0;
}