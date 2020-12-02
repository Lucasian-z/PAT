#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

/*
author: zhanghao
email: zhangh2548@outlook.com
date:2020/08/01/ 12:04:20
*/

struct node {
    int val;//weight
    int rank;
};

int main()
{
    int M, N, num;
    scanf("%d%d", &M, &N);
    node *arr = (node *)malloc(sizeof(node) * M);
    for (int i = 0; i < M; ++i) {
        scanf("%d", &arr[i].val);
        arr[i].rank = ceil((double)M / N) + 1;
    }
    queue<int> que;
    for (int i = 0; i < M; ++i) {
        scanf("%d", &num);//初始给定序列
        que.push(num);
    }
    while (!que.empty()) {
        int size = que.size();
        int r = ceil((double)size / N) + 1;//当轮排名
        //printf("r = %d\n", r);
        int MAX = -1, MAXI = -1;
        for (int i = 0; i < size; ++i) {
            int top = que.front();
            //printf("top = %d\n", top);
            que.pop();
            arr[top].rank = r;
            if (size == 1) {
                --arr[top].rank;//最后一轮
                break;
            }
            if (arr[top].val > MAX) {//找到最大值及其下标
                MAX = arr[top].val;
                MAXI = top;
            }
            if (i % N == N - 1 && MAXI != -1 || i == size - 1 && MAXI != -1) {//找到当前轮的最大值，并把下标加入队列
                //printf("i = %d,MAXI = %d\n", i, MAXI);
                que.push(MAXI);
                MAX = MAXI = -1;

            }    
        }
    }
    for (int i = 0; i < M; ++i) {
        if (i) printf(" ");
        printf("%d", arr[i].rank);
    }
    return 0;
}