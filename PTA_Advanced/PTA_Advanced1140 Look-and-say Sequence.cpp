#include <iostream>
#include <string>
using namespace std;

int main()
{
    string D, res;
    int cnt = 1, N;
    cin >> D >> N;
    --N;
    while (N--) {
        
        for (int i = 0; i < D.length(); ++i) {
            if (i + 1 < D.length() && D[i] != D[i+1] || i == D.length() - 1) {
                res += D[i] + to_string(cnt);
                cnt = 1;
            }else if (i + 1 < D.length() && D[i] == D[i+1]) {
                ++cnt;
            }
        }
        D = res;
        res = "";
    }
    cout << D << endl;
    return 0;
}