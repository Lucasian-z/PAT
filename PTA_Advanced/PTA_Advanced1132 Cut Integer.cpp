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
    string num,n1,n2;
    long long x1, x2;
    while (K--) {
        cin >> num;
        n1 = num.substr(0, num.size() / 2);
        n2 = num.substr(num.size() / 2);
        x1 = stol(n1);
        x2 = stol(n2);
        if (x1 * x2 != 0 && stol(num) % (x1 * x2) == 0) {
            printf("Yes\n");
        }else {
            printf("No\n");
        }
    }
    return 0;
}