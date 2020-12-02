//#include <iostream>
//#include <string>
//using namespace std;
//
//string chineseNum1[5] = { "", "", "Shi", "Bai", "Qian" };
//string chineseNum2[10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
//
//string readFourNum(string str) {
//	string res;
//	for (int i = 0; i < str.size();) {
//		if (str[i] == '0') {			
//			while (str[i] == '0') ++i;
//			if (i != str.size())
//				res += "ling ";
//		}
//		else {
//			res += chineseNum2[str[i] - '0'] + " " + chineseNum1[str.size() - i] + " ";
//			++i;
//		}
//	}
//	while (res[res.size() - 1] == ' ')
//		res.erase(res.size()-1);
//	return res;
//}
//int main()
//{
//	string num;
//	cin >> num;
//	string num_dup = num;
//	if (num[0] == '-') {
//		num = num.substr(1);
//	}		
//	int i = 0;
//	for (; i < num.size() - 1 && num[i] == '0'; ++i);
//	num = num.substr(i);
//	int pos = num.size() % 4;
//	string ans;
//	if (num[0] == '0') {
//		printf("ling");
//		return 0;
//	}
//	else if(num.size() > 4) {		
//		i = 1;
//		while (i < num.size() && num[i] == '0') ++i;
//		if (i == num.size()) {
//			if (num_dup[0] == '-') printf("Fu ");
//			if (i > 8)
//				cout << readFourNum(num.substr(0, pos)) << " Yi" << endl;
//			else if (i == 8) cout << readFourNum(num.substr(0, 4)) << " Wan" << endl;
//			else if (i > 4) cout << readFourNum(num.substr(0, pos)) << " Wan" << endl;
//			return 0;
//		}
//	}
//	if (num_dup[0] == '-') printf("Fu ");
//	if (num.size() > 8) {
//		ans = readFourNum(num.substr(0, pos)) + " Yi ";
//		if (num.substr(pos, 4) != "0000")
//			ans += readFourNum(num.substr(pos, 4)) + " Wan ";
//		//else ans += "ling ";
//		ans += readFourNum(num.substr(5));
//	}
//	else if (num.size() > 4) {
//		ans = readFourNum(num.substr(0, pos)) + " Wan " + readFourNum(num.substr(pos));
//	}
//	else ans = readFourNum(num);
//	cout << ans << endl;
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;

string chineseNums[10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
string wei[5] = { "Shi", "Bai", "Qian", "Wan", "Yi" };
int main()
{
	string num;
	cin >> num;
	int len = num.size();
	int left = 0, right = len - 1;
	if (num[0] == '-') {//若为负，则输出Fu，并将left右移
		printf("Fu");
		++left;
	}	
	while (left + 4 <= right) {
		right -= 4;		
	}
	while (left < len) {
		int isPrint = 0;//表示该部分未输出过
		int flag = 0;//是否累积有0
		while (left <= right) {
			if (left > 0 && num[left] == '0') {//若当前位为0
				flag = 1;
			}
			else {//若当前位不为0
				if (flag) {//如果存在累积0
					printf(" ling");
					flag = 0;
				}
				if (left > 0) printf(" ");//只要不是首位，则都要输出空格
				isPrint = 1;//置为已输出过
				cout << chineseNums[num[left] - '0'];//打印对应数字
				if (left != right) cout << " " << wei[right - left - 1];//只要不是个位，要输出十百千			
			}
			++left;
		}
		if (isPrint && right != len - 1) {//只要不是个位，输出万or亿
			cout << " " << wei[(len - 1 - right) / 4 + 2];
		}
		right += 4;
	}
	return 0;
}