#include <iostream>
#include <map>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str1, str2;
    string res;
    cin >> str1 >> str2;
    size_t i, j, k;
    for(i = 0, j = 0; i < str1.length() || j < str2.length();)
    {
        if(str1[i] != str2[j])
        {
            
            for(k = 0; k < res.size(); ++k)
                if(res[k] == ((str1[i]) >= 'a' && str1[i] <= 'z' ? str1[i]-32:str1[i]))
                    break;
            if(k == res.size())
                res.push_back((str1[i]) >= 'a' && str1[i] <= 'z' ? str1[i]-32:str1[i]);
            ++i;
        }
        else
        {
            ++i;
            ++j;
        }
    }
    cout << res << endl;
    return 0;
}