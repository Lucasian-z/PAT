#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int N = 0, i = 0, j = 0;
    cin >> N;
    getchar();
    string str;
    map<int, int> res;
    while (N--)
    {
        getline(cin, str);
        for(i = 0; str[i] != '-'; ++i);
        for(j = 0; str[j] != ' '; ++j);
        ++j;
        res[stoi(str.substr(0, i))] += stoi(str.substr(j));
    }   
    int maxi = 0;
    for(const auto &item : res)
    {
        if(res[maxi] < item.second)
            maxi = item.first;
    }
    cout << maxi << " " << res[maxi] << endl;
    return 0;
}