#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string add(string &a, string &b) {
    string res;
    int len1 = a.length(), len2 = b.length();
    int carry = 0;
    for (int i = 0; i < len1 || i < len2; ++i) {
        int s = carry;
        if (i < len1) {
            s += a[i] - '0';
        }
        if (i < len2) {
            s += b[i] - '0';
        }
        res += (s % 10) + '0';
        carry = s / 10;
    }
    if (carry) {
        res += carry + '0';
    }
    return res;
}

bool isPalid(string &str) {
    int len = str.length();
    for (int i = 0, j = len - 1; i < j; ++i, --j) {
        if (str[i] != str[j]) {
            return false;
        }
    }
    return true;
}

int main()
{
    string a, b;
    int cnt;
    cin >> a >> cnt;
    int cnt1 = cnt;
    b = a;
    reverse(a.begin(), a.end());
    while (cnt--) {
        if (isPalid(a)) {
            cout << a << endl << cnt1 - 1 - cnt << endl;
            return 0;
        }
        b = add(a, b);
        a = b;
        reverse(a.begin(), a.end());
    }
    cout << a << endl << cnt1 << endl;
    return 0;
}