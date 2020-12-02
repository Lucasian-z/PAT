#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

struct info {
    int x,y;
    int id;
};

bool cmp(info &a, info &b) {
    if (a.x + a.y != b.x + b.y) {
        return a.x + a.y > b.x + b.y;
    }
    if (a.x != b.x) {
        return a.x > b.x;
    }
    return a.id < b.id;
}

int main()
{
    vector<info> sages;
    vector<info> noblemans;
    vector<info> foolmans;
    vector<info> smallmans;
    int N, L, H;
    info p;
    scanf("%d%d%d", &N, &L, &H);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d%d", &p.id, &p.x, &p.y);
        if (p.x >= H && p.y >= H) {
            sages.push_back(p);
        }else if (p.y >= L && p.y < H && p.x >= H) {
            noblemans.push_back(p);
        }else if (p.y < H && p.x < H && p.x >= p.y && p.y >= L && p.x >= L) {
            foolmans.push_back(p);
        }else if (p.y >= L && p.x >= L) {
            smallmans.push_back(p);
        }
    }
    printf("%d\n", sages.size() + noblemans.size() + foolmans.size() + smallmans.size());
    sort(sages.begin(), sages.end(), cmp);
    sort(noblemans.begin(), noblemans.end(), cmp);
    sort(foolmans.begin(), foolmans.end(), cmp);
    sort(smallmans.begin(), smallmans.end(), cmp);
    for (auto &item : sages) {
        printf("%d %d %d\n", item.id, item.x, item.y);
    }
    for (auto &item : noblemans) {
        printf("%d %d %d\n", item.id, item.x, item.y);
    }
    for (auto &item : foolmans) {
        printf("%d %d %d\n", item.id, item.x, item.y);
    }
    for (auto &item : smallmans) {
        printf("%d %d %d\n", item.id, item.x, item.y);
    }
    return 0;
}