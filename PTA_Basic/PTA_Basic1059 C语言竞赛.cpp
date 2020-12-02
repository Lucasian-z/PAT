#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if(n < 2)
        return false;
    if(n == 2)
        return true;
    for(int i = 2; i <= sqrt(n); ++i)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    map<string, int> ID;
    int N = 0, i = 0, K = 0;
    cin >> N;
    string id;
    while (i < N)
    {
        cin >> id;
        ID[id] = i+1;
        ++i;
    }
    cin >> K;
    while (K--)
    {
        cin >> id;
        if(ID[id] == -1)
            cout << id << ": Checked" << endl;
        else if(ID[id] == 0)
            cout << id << ": Are you kidding?" << endl;
        else if(ID[id] == 1)
        {
            cout << id << ": Mystery Award" << endl;
            ID[id] = -1;
        }
            
        else if(isPrime(ID[id]))
        {
            cout << id << ": " << "Minion" << endl;
            ID[id] = -1;
        }
        else
        {
            cout << id << ": " << "Chocolate" << endl;
            ID[id] = -1;
        }
    }
    return 0;
}