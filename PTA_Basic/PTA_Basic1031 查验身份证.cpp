#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int N;
    int ret = scanf("%d", &N);
    if(ret != 1)
        return 0;
    string id;
    vector<string> ivec;
    int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    int com[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
    int sum = 0, flag = 0;
    while (N--)
    {
        cin >> id;
        flag = 0;
        sum = 0;
        for(int i = 0; i < 17; ++i)
        {
            if(!(id[i] >= '0' && id[i] <= '9'))
            {
                flag = 1;
                break;
            }
            sum += weight[i]*(id[i]-'0');
        }
        sum %= 11;
        if(com[sum] != id[17])
            flag = 1;
        if(flag)
            ivec.push_back(id);
    }
    if(ivec.empty())
        cout << "All passed" << endl;
    else
    {
        for(const auto &item : ivec)
            cout << item << endl;
    }
    return 0;
}