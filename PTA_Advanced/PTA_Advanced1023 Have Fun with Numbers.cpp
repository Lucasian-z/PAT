#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string &a) {
    string res;
    int len = a.length();
    int carry = 0;
    for (int i = 0; i < len; ++i) {
        int s = carry;
        s += (a[i] - '0') * 2;
        res += (s % 10) + '0';
        carry = s / 10;
    }
    if (carry) {
        res += carry + '0';
    }
    return res;
}

bool solve(string &a, string &b) {
    int a1[10] = {0}, b1[10] = {0};
    for (auto &it : a) {
        ++a1[it-'0'];
    }
    for (auto &it : b) {
        ++b1[it-'0'];
    }
    for (int i = 0; i < 10; ++i) {
        if (a1[i] != b1[i]) {
            return false;
        }
    }
    return true;
}
int main()
{
    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    string res = add(str);
    if (solve(res, str)) {
        printf("Yes\n");        
    }else {
        printf("No\n");
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}