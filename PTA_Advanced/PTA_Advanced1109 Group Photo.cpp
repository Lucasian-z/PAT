#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/08/02/ 22:27:15
*/

struct node {
    string name;
    int height;
};


int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    vector<node> person(N);
    for (int i = 0; i < N; ++i) {
        cin >> person[i].name >> person[i].height;
    }
    sort(person.begin(), person.end(), [](node &a, node &b) { 
        if (a.height != b.height) return a.height > b.height;
        return a.name < b.name;
        });
    vector<int> res;
    int left, right, flag = 0;
    for (int i = 0; i < K; ++i) {
        if (i == 0)
            left = 0, right = N % K + N / K;
        else
            left = right, right += N / K;
        flag = 0;
        for (int j = left; j < right; ++j) {//交替插入
            if (!flag) {
                res.push_back(j);
                flag = 1;
            }else {
                res.insert(res.begin(), j);
                flag = 0;
            }
        }
        for (int j = 0; j < res.size(); ++j) {
            if (j) printf(" ");
            printf("%s", person[res[j]].name.c_str());
        }
        printf("\n");
        res.clear();
    }
    return 0;
}