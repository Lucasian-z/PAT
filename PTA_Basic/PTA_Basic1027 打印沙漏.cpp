#include <iostream>
using namespace std;
void printHourglass(int n, char c)
{
    if(n == 0)
        return;
    int i = 3, j = 0, sum = 1, row = 1;
    for(; sum < n; i+=2)
    {
        sum += 2*i;
        if(sum > n)
        {
            sum -= 2*i;
            break;
        }
        ++row;
    }
    // cout << row << endl;
    // cout << sum << endl;
    while(j < row)
    {
        for(i = 0; i < j; ++i)
            cout << " ";
        for(i = 0; i < 2*(row-j)-1; ++i)
            cout << c;
        cout << endl;
        ++j;
    }
    j = row-1;
    while (j)
    {
        for(i = 0; i < j-1; ++i)
            cout << " ";
        for(i = 0; i < 2*(row-j)+1; ++i)
            cout << c;
        cout << endl;
        --j;
    }
    
    cout << n-sum << endl;
}
int main()
{
    int n = 0;
    char c;
    cin >> n >> c;
    printHourglass(n, c);
    return 0;
}