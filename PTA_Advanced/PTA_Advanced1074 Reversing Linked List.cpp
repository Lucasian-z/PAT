#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
author: zhanghao
email: zhangh2548@outlook.com
date:2020/08/01/ 19:52:40
*/

const int maxn = 1000010;
struct node {
    int addr;
    int val;
    int next;
};
vector<node> list(maxn);
vector<node> list1;
int main()
{
    int baseAddr, N, gap;
    int addr, val, next;
    scanf("%d%d%d", &baseAddr, &N, &gap);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d", &addr, &val, &next);
        list[addr].addr = addr;
        list[addr].val = val;
        list[addr].next = next;
    }
    while (baseAddr != -1) {
        list1.push_back(list[baseAddr]);
        baseAddr = list[baseAddr].next;
    }
    //printf("list.size() = %d\n", list1.size());
    for (int i = 0; i < list1.size() / gap; ++i) {
        reverse(list1.begin() + i * gap, list1.begin() + (i + 1) * gap);
    }
    for (int i = 0; i < list1.size()-1; ++i) {
        printf("%05d %d %05d\n", list1[i].addr, list1[i].val, list1[i+1].addr);
    }
    printf("%05d %d -1\n", list1.back().addr, list1.back().val);
    return 0;
}