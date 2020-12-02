#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<string> ivec;
    string word;
    while (cin >> word)
    {
        ivec.push_back(word);
        if(cin.get() == '\n')
            break;
    }
    for(auto it = ivec.rbegin(); it != ivec.rend()-1; ++it)
    {
        cout << *it << " ";
    }
    cout << *ivec.begin();
    return 0;
}