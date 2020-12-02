#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int n = str.length(), res = 1;
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    vector<vector<int>> dp(n, vector<int> (n, 0));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
        if (i > 0 && str[i] == str[i-1]) {
            dp[i-1][i] = 1;
            res = 2;
        }
    }
    for (int len = 2; len < n; ++len) {
        for (int i = 0; i + len < n; ++i) {
            if (str[i] == str[i + len] && dp[i+1][i+len-1] == 1) {
                dp[i][i+len] = 1;
                res = len + 1;
            }   
        }
    }
    printf("%d\n", res);
    return 0;
}