#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
author: zhanghao
email: zhangh2548@outlook.com
date:2020/08/01/ 16:35:03
*/

int main()
{
    string str, tmp;
    map<string, int> imap;
    getline(cin, str);
    int j = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (!isalnum(str[i])) {//类似hh***hhh
            tmp = str.substr(j, i - j);
            while (tmp.size() >= 1 && ispunct(tmp[0])) {
                tmp.erase(tmp.begin());
            }
            while (tmp.size() >= 1 && ispunct(tmp.back())) {
                tmp.pop_back();
            }
            j = i + 1;
        }else if (i == str.length() - 1) {
            tmp = str.substr(j, i - j + 1);
            while (tmp.size() >= 1 && ispunct(tmp[0])) {
                tmp.erase(tmp.begin());
            }
            while (tmp.size() >= 1 && ispunct(tmp.back())) {
                tmp.pop_back();
            }
            //break;
        }
        if (tmp.size()){
            //cout << "tmp = " << tmp << endl;
            for (int k = 0; k < tmp.size(); ++k) {
                if (isupper(tmp[k])) {
                    tmp[k] += 32;
                }
            }
            ++imap[tmp];
            tmp = "";
        }
            
    }
    string res;
    int MAX = 0;
    for (auto it : imap) {
        if (it.second > MAX) {
            MAX = it.second;
            res = it.first;
        }else if (it.second == MAX) {
            res = min(res, it.first);
        }
    }
    cout << res << " " << MAX << endl;
    return 0;
}