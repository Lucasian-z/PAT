#include <iostream>
#include <string>
#include <vector>
using namespace std;
                                    
int main()
{
    string str, substr;
    vector<string> ivec1, ivec2, ivec3;
    int i = 0;
    while (i < 3)
    {
        getline(cin, str);
        substr = "";
        for(size_t k = 0; k < str.size(); ++k)
        {
            if(str[k] == '[')
            {
                ++k;
                while (str[k] != ']')
                {
                    substr += str[k++];
                }
                if(str[k] == ']')
                {
                    if(i == 0)
                        ivec1.push_back(substr);
                    else if(i == 1)
                        ivec2.push_back(substr);
                    else
                        ivec3.push_back(substr);
                    substr = "";
                }
            }
        }   
        ++i;
    }
    int N = 0;
    cin >> N;
    int a[5] = {0};
    while (N--)
    {
        i = 0;
        while (i < 5)
        {
            cin >> a[i];
            ++i;
        }
        if(a[0] > ivec1.size() || a[1] > ivec2.size() || a[2] > ivec3.size() || \
          a[3] > ivec2.size() || a[4] > ivec1.size())
          cout << "Are you kidding me? @\\/@" << endl;
        else if(a[0] < 1 || a[1] < 1 || a[2] < 1 || a[3] < 1 || a[4] < 1)
            cout << "Are you kidding me? @\\/@" << endl;
        else
            cout << ivec1[a[0]-1] << "(" << ivec2[a[1]-1] << ivec3[a[2]-1] << ivec2[a[3]-1]\
                 << ")" << ivec1[a[4]-1] << endl;
    }
    return 0;
}