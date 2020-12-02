#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    Solution()
    {
        res = 0;
        cin >> _str;
    }
    void strSum()
    {
        for(size_t i = 0; i != _str.size(); ++i)
        {
            res += (_str[i]-'0');
        }
        string tmp = to_string(res);
        size_t i = 0;
        for(; i != tmp.size()-1; ++i)
            cout << ivec[tmp[i]-'0'] << " ";
        cout << ivec[tmp[i]-'0'] << endl;
    }
private:
    int res;
    string _str;
    vector<string> ivec{"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
};

int main()
{
    Solution s;
    s.strSum();
    return 0;
}