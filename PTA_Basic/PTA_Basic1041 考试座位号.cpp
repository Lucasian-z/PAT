#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    string sId, tmpSeat, realSeat;
    int N;
    map<string, string> imap;
    cin >> N;
    while (N--)
    {
        cin >> sId >> tmpSeat >> realSeat;
        string res = sId + " " + realSeat;
        imap[tmpSeat] = res;
    }
    
    int n;
    cin >> n;
    while (n--)
    {
        cin >> tmpSeat;
        cout << imap[tmpSeat] << endl;
    }
    return 0;
}