#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

int main()
{
    int K;
    scanf("%d", &K);
    set<char> iset;
    char str[1000];
    scanf("%s", str);
    for (int i = 0; i < strlen(str); ++i) {
        iset.insert(str[i]);
    }
    for (int i = 0; i < strlen(str);) {
        int j = i;
        for (; j < i + K; ++j) {
            if (j + 1 < i + K && str[j] != str[j+1]) {
                iset.erase(str[j]);
                i = j + 1;
                break;
            }
        }
        if (j == i + K) i += K;
    }
    auto iset1 = iset;
    for (int i = 0; i < strlen(str); ++i) {
        if (iset1.find(str[i]) != iset1.end()) {
            printf("%c", str[i]);
            iset1.erase(str[i]);
        }
    }
    if (!iset.empty()) printf("\n");
    char res[1000];
    int idx = 0;
    for (int i = 0; i < strlen(str);) {
        if (iset.find(str[i]) == iset.end()) {
            res[idx++] = str[i++];
        }else {
            res[idx++] = str[i];
            i += K;
        }
    }
    res[idx] = '\0';
    puts(res);
    return 0;
}