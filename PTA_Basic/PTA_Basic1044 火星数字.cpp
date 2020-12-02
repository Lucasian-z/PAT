#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<string> Mars_num{"tret", "jan", "feb", "mar", "apr", "may",
                            "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    vector<string> Mars_num2{"", "tam", "hel", "maa", "huh", "tou", "kes",
                             "hei", "elo", "syy", "lok", "mer", "jou"};
    vector<string> ivec;
    int N = 0;
    cin >> N;
    getchar();
    while (N--)
    {
        string str, res;
        getline(cin, str);
        if (str[0] >= '0' && str[0] <= '9')
        {
            res += Mars_num2[stoi(str) / 13];
            if (stoi(str) < 13)
            {
                if (stoi(str) / 13 != 0)
                    res += " " + Mars_num[stoi(str) % 13];
                else
                    res += Mars_num[stoi(str) % 13];
            }
            else
            {
                if (stoi(str) % 13)
                    res += " " + Mars_num[stoi(str) % 13];
            }
        }
        else
        {
            if (str.size() <= 4)
            {
                if (find(Mars_num.begin(), Mars_num.end(), str) != Mars_num.end())
                    res = to_string((find(Mars_num.begin(), Mars_num.end(), str) -
                                     Mars_num.begin()));
                else
                {
                    res = to_string((find(Mars_num2.begin(), Mars_num2.end(), str) - Mars_num2.begin()) * 13);
                }
            }
            else
            {
                string str1 = str.substr(0, 3), str2 = str.substr(4);
                res = to_string((find(Mars_num2.begin(), Mars_num2.end(), str1) - Mars_num2.begin()) * 13 + (find(Mars_num.begin(), Mars_num.end(), str2)) - Mars_num.begin());
            }
        }
        ivec.push_back(res);
    }
    for (const auto &item : ivec)
        cout << item << endl;
    return 0;
}