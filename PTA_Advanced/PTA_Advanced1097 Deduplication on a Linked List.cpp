#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
struct node {
    int val;
    int next;
};
vector<node> list(100000);


int main()
{
    int baseAddress = 0, cnt = 0;
    int addr, val, next;
    scanf("%d%d", &baseAddress, &cnt);
    if (cnt == 0) return 0;
    set<int> nums;
    vector<pair<int, int>> del;
    int pre = baseAddress, base = pre, cnt1 = cnt;
    while (cnt--) {
        scanf("%d%d%d", &addr, &val, &next);
        list[addr].val = val;
        list[addr].next = next;
    }
    int validCnt = 0; //有效节点个数
    while (baseAddress != -1) {
        if (nums.find(abs(list[baseAddress].val)) != nums.end()) {
            list[pre].next = list[baseAddress].next;

            del.push_back(make_pair(baseAddress, list[baseAddress].val));
        }else {
            pre = baseAddress;
        }
        nums.insert(abs(list[baseAddress].val));
        baseAddress = list[baseAddress].next;
        ++validCnt;
    }
    int n = validCnt - del.size();
    for (int i = 0; i < n; ++i) {
        if (i < n - 1) {
            printf("%05d %d %05d\n", base, list[base].val, list[base].next);
        }else {
            printf("%05d %d -1\n", base, list[base].val);
        }
        base = list[base].next;
    }
    for (int i = 0; i < del.size(); ++i) {
        if (i < del.size() - 1) {
            printf("%05d %d %05d\n", del[i].first, del[i].second, del[i+1].first);
        }else {
            printf("%05d %d -1\n", del[i].first, del[i].second);
        }
    }
    return 0;
}