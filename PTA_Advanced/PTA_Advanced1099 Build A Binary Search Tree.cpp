#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef struct node {
    int val;
    int left = -1, right = -1;
}Node;

vector<Node> tree(100);
vector<int> inOrd;
int arr[100];

void inOrder(int i, int idx) {
    if (i == -1) {
        return;
    }
    inOrder(tree[i].left, idx);
    inOrd.push_back(i);
    inOrder(tree[i].right, ++idx);
}
void levelOrder(int i) {
    queue<int> que;
    que.push(i);
    int flag = 0;
    while (!que.empty()) {
        int top = que.front();
        if (flag == 1) {
            printf(" ");
        }
        printf("%d", tree[top].val);
        flag = 1;
        que.pop();
        if (tree[top].left != -1) {
            que.push(tree[top].left);
        }
        if (tree[top].right != -1) {
            que.push(tree[top].right);
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int l, r;
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &l, &r);
        tree[i].left = l;
        tree[i].right = r;
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);
    inOrder(0, 0);
    for (int i = 0; i < N; ++i) {
        tree[inOrd[i]].val = arr[i];
    }
    levelOrder(0);
    return 0;
}