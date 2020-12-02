#include <iostream>
#include <string>
using namespace std;

bool isValid(string str) {
    int dotCnt = 0;
    if (str[0] != '-' && !(str[0] >= '0' && str[0] <= '9')) {
        return false;
    }
    for (int i = 1; i < str.length(); ++i) {
        if (str[i] == '.') {
            ++dotCnt;
            if (str.length() - i - 1 > 2) return false;
            continue;
        }
        if (!(str[i] >= '0' && str[i] <= '9')) {
            return false;
        }
    }
    return dotCnt <= 1;
}

int main()
{
    string str;
    int N, cnt = 0;
    double sum = 0.0, num = 0.0;
    cin >> N;
    while(N--) {
        cin >> str;
        if (isValid(str) && stof(str) <= 1000 && stof(str) >= -1000) {
            ++cnt;
            sum += stof(str);
        }else {
            printf("ERROR: %s is not a legal number\n", str.c_str());
        }
    }
    if (cnt == 0) {
        printf("The average of 0 numbers is Undefined\n");
    }else if (cnt == 1) {
        printf("The average of 1 number is %.2f\n", sum);
    }else {
        printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
    }
    return 0;
}