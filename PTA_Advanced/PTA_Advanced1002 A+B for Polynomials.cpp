#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int K = 0, i = 0;
    map<string, double> poly;
    string exp;
    double coff;
    set<double> iset;
    for(int j = 0; j < 2; ++j)
    {
        int ret = scanf("%d",&K);
        if(ret != 1)
            return 0;
        for(i = 0; i < K; ++i)
        {
            cin >> exp >> coff;
            iset.insert(stof(exp));
            poly[to_string(stof(exp))] += coff;
        }
    }
    int cnt = 0;
    for(auto it = iset.rbegin(); it != iset.rend(); ++it)
    {
        if(fabs(poly[to_string(*it)]-0) > 1E-8)
            ++cnt;
    }
    printf("%d", cnt);
    for(auto it = iset.rbegin(); it != iset.rend(); ++it)
    {
        if(fabs(poly[to_string(*it)]-0) > 1E-8)
            printf(" %.0f %.1f", *it, poly[to_string(*it)]);
    }
    return 0;
}
