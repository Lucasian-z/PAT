#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> imap;
    int N, score;
    cin >> N;
    while (N--)
    {
        cin >> score;
        ++imap[score];
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> score;
        cout << imap[score];
        if(i != n-1)
            cout << " ";
    }
    return 0;
}