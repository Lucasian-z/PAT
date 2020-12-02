#include <iostream>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

/*
author: zhanghao
email: zhangh2548@outlook.com
date:2020/08/01/ 16:16:04
*/

const int maxn = 1010;
int tree[maxn], arr[maxn], idx = 0, n;

//中序遍历建立完全二叉树
void create(int root) {
    if (root >= n) {
        return;
    }
    create(root * 2 + 1);
    tree[root] = arr[idx++];
    create(root * 2 + 2);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    create(0);
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", tree[i]);
    }
    return 0;
}