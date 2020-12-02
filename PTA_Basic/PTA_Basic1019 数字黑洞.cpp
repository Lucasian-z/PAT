#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;
    str.insert(0, 4-str.size(), '0');
    while(1)
    {
        sort(str.begin(), str.end());
        string str2 = str;
        reverse(str2.begin(), str2.end());

        int number = stoi(str);
        int number2 = stoi(str2);
        printf("%04d - ",number2);
        printf("%04d = ",number);
        
        printf("%04d\n",number2-number);
        str = to_string(number2-number);
        int i = str.size();
        while(i++ < 4)
            str.insert(str.begin(), '0');
        if(number2-number == 6174 || number2 == number)
            break;
    }
    return 0;
}