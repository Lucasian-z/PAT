#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    vector<int> ivec;
    ivec.reserve(N);
    int cnt, num, i, max;
    for (i = 0; i < N; ++i)
    {
        cin >> num;
        ivec.push_back(num);
    }
    vector<int> ivec1(ivec.begin(), ivec.end());
    vector<int> res;
    sort(ivec1.begin(), ivec1.end());
    size_t j;
    max = ivec[0];
    for (j = 0; j < ivec.size(); ++j)
    {
        if (max < ivec[j])
            max = ivec[j];
        if (ivec[j] == ivec1[j] && max <= ivec[j])
        {
            res.push_back(ivec[j]);
        }
    }
    cout << res.size() << endl;
    if (res.size() > 0)
    {
        for (j = 0; j < res.size() - 1; ++j)
            cout << res[j] << " ";
        cout << res[j];
    }
    else
        cout << endl;
    return 0;
}