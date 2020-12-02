#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
using namespace std;

int main()
{
    map<string, set<int>> imap[5];
    string str, tmp;
    int M, N, id;
    scanf("%d", &M);
    while (M--) {
        scanf("%d", &id);
        getchar();
        getline(cin, str);
        imap[0][str].insert(id);
        getline(cin, str);
        imap[1][str].insert(id);
        getline(cin, str);
        int j = 0;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == ' ') {
                tmp = str.substr(j, i - j);
                imap[2][tmp].insert(id);
                j = i + 1;
            }else if (i == str.length() - 1) {
                tmp = str.substr(j, i - j + 1);
                imap[2][tmp].insert(id);
            }
        }
        getline(cin, str);
        imap[3][str].insert(id);
        getline(cin, str);
        imap[4][str].insert(id);
        //getchar();
    }    
    scanf("%d", &N);
    getchar();
    while (N--) {
        getline(cin, str);
        cout << str << endl;
        int i = str[0] - '0' - 1;
        str = str.substr(3);
        int flag = 0;
        for (auto it = imap[i].begin(); it != imap[i].end(); ++it) {
            if (it->first == str) {
                for (auto it : it->second) {
                    printf("%07d\n", it);
                }
                flag = 1;
            }
        }
        if (flag == 0) {
            printf("Not Found\n");
        }
    }
    return 0;
}