#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar();
    string info;
    map<int, string> imap;
    int score;
    for(int i = 0; i < n; ++i)
    {   
        getline(cin, info);
        size_t j = info.size()-1;
        while(info[j] != ' ')
            --j;
        score = stoi(info.substr(j+1));
        imap[score] = info.substr(0, j);
    }
    auto it = imap.end();
    --it;
    cout << it->second << endl;
    cout << imap.begin()->second;
    return 0;
}