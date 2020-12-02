#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
map<char, char> mod{ {'1','@'},{'0' , '%'},{'l' , 'L'},{'O' , 'o'} };
int main()
{
	int N, i;
	string id, pwd;
	cin >> N;
	vector<string> res;
	for (i = 0; i < N; ++i) {
		int flag = 0;
		cin >> id >> pwd;
		for (size_t j = 0; j < pwd.size(); ++j) {
			if (mod.find(pwd[j]) != mod.end()) {
				flag = 1;
				pwd[j] = mod[pwd[j]];
			}			
		}
		if (flag) {
			res.push_back(id + " " + pwd);
		}
	}
	if (res.empty()) {
		if (N > 1) printf("There are %d accounts and no account is modified", N);
		else printf("There is 1 account and no account is modified");
	}
	else {
		printf("%d\n", res.size());
		for (i = 0; i < (int)res.size(); ++i)
			printf("%s\n", res[i].c_str());
	}
	return 0;
}