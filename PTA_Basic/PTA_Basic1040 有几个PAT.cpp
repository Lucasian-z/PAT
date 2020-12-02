#include <iostream>
using namespace std;
const int N = 1000000007;
int main()
{
    int p = 0, pa = 0, pat = 0;
    char c;
    while ((c = getchar()) != '\n')
    {
        if (c == 'P')
            ++p;
        if (c == 'A')
            pa = (pa + p) % N;
        if (c == 'T')
            pat = (pat + pa) % N;
    }
    cout << pat << endl;
    return 0;
}