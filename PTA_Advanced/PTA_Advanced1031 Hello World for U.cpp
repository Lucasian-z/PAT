#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n1,n2;
    for(n2 = 3; n2 < str.size(); ++n2){
        for(n1 = n2; n1 > 0; --n1){
            if(2 * n1 + n2 - 2 == str.size()){
                for(int i = 0; i < n1-1; ++i){
                    cout << str[i] << string(n2-2, ' ') << str[str.size()-i-1] << endl;
                }
                cout << str.substr(n1-1, n2) << endl;
                return 0;
            }
            else if(2 * n1 + n2 - 2 < str.size()) break;
        }
    }
    return 0;
}
