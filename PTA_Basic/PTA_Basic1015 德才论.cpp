#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info
{
    int _no;
    int _score1;
    int _score2;
    int _score;
};
ostream &operator<<(ostream &os, const info &item)
{
    os << item._no << " " << item._score1 << " " << item._score2;
    return os;
}
bool infoSort(info a, info b)
{
    if(a._score > b._score)
        return true;
    else if(a._score == b._score)
    {
        if(a._score1 > b._score1)
            return true;
        else if(a._score1 == b._score1)
            return a._no < b._no;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    int N, L, H;
    int no, score1, score2;
    int res = scanf("%d %d %d", &N, &L, &H);
    if(res != 3)
        return -1;
    vector<info> ivec1, ivec2, ivec3, ivec4;
    for(int i = 0; i < N; ++i)
    {
        int res = scanf("%d %d %d", &no, &score1, &score2);
        if(res != 3)
            return -1;
        if(score1 >= L && score2 >= L)
        {
            if(score1 >= H && score2 >= H)
                ivec1.push_back({no, score1, score2, score1+score2});
            else if(score1 >= H && score2 < H)
                ivec2.push_back({no, score1, score2, score1+score2});
            else if(score1 >= score2)
                ivec3.push_back({no, score1, score2, score1+score2});
            else 
                ivec4.push_back({no, score1, score2, score1+score2});
        }
        
    }
    sort(ivec1.begin(), ivec1.end(), infoSort);
    sort(ivec2.begin(), ivec2.end(), infoSort);
    sort(ivec3.begin(), ivec3.end(), infoSort);
    sort(ivec4.begin(), ivec4.end(), infoSort);
    int i;
    cout << ivec1.size() + ivec2.size() + ivec3.size() + ivec4.size() << endl;
    ivec1.insert(ivec1.end(), ivec2.begin(), ivec2.end());
    ivec1.insert(ivec1.end(), ivec3.begin(), ivec3.end());
    ivec1.insert(ivec1.end(), ivec4.begin(), ivec4.end());
    for(i = 0; i < ivec1.size(); ++i)
    {
        cout << ivec1[i] << endl;
    }

    return 0;
}