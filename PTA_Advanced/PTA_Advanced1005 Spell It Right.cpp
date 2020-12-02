#include <iostream>
#include <string>
using namespace std;
string words[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main()
{
    string num_str;
    cin >> num_str;
    int sum = 0;
    for(const auto &item: num_str)
    {
        sum += item-'0';
    }
    string res_str = to_string(sum);
    size_t i = 0;
    for(; i < res_str.size()-1; ++i)
    {
        cout << words[res_str[i]-'0'] << " ";
    }
    cout << words[res_str[i]-'0'];
    return 0;
}
