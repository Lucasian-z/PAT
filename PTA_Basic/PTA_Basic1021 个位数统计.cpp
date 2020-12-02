#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string str;
    cin >> str;
    map<int, int> imap;
    for(auto const &item : str)
    {
        ++imap[item-'0'];
    }
    for(auto it = imap.begin(); it != imap.end(); ++it)
    {
        cout << it->first << ":" << it->second << endl;
    }
    return 0;
}