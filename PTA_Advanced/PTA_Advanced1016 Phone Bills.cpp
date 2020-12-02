#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
//本题关键在于如果某人某月无费用产生，则不能输出该用户信息
int tolls[24] = { 0 };
int compute(string time1, string time2, int& minutes) {
	int d1 = stoi(time1.substr(3, 2)), h1 = stoi(time1.substr(6, 2)), m1 = stoi(time1.substr(9));
	int d2 = stoi(time2.substr(3, 2)), h2 = stoi(time2.substr(6, 2)), m2 = stoi(time2.substr(9));
	//cout << "h1 = " << h1 << " h2 = " << h2 << endl;
	int sum = 0;
	while (d1 != d2 || h1 != h2 || m1 != m2) {
		sum += tolls[h1];//累加当前时间的话费
		++m1;//累加分钟数
		++minutes;
		if (m1 == 60) {//小时数+1
			++h1;
			m1 = 0;
		}
		if (h1 == 24) {//天数+1
			++d1;
			h1 = 0;
		}
	}
	//愚蠢的办法
	//if (d1 == d2) {//在同一天
	//	if (h1 == h2) {
	//		sum = (m2 - m1) * tolls[h1];
	//		minutes += m2 - m1;
	//	}
	//	else {
	//		sum += (60 - m1) * tolls[h1];
	//		minutes += 60 - m1;
	//		for (int i = h1 + 1; i < h2; ++i) {
	//			sum += 60 * tolls[i];
	//			minutes += 60;
	//		}
	//		sum += m2 * tolls[h2];
	//		minutes += m2;
	//	}
	//}
	//else {//不在同一天
	//	sum += (60 - m1) * tolls[h1];
	//	minutes += 60 - m1;
	//	for (int i = h1 + 1; i < 24; ++i) {
	//		sum += 60 * tolls[i];
	//		minutes += 60;
	//	}
	//	for (int i = d1 + 1; i < d2; ++i) {
	//		for (int j = 0; j < 24; ++j)
	//			sum += 60 * tolls[j];
	//		minutes += 24 * 60;
	//	}
	//	for (int i = 0; i < h2; ++i) {
	//		sum += 60 * tolls[i];
	//		minutes += 60;
	//	}
	//	sum += m2 * tolls[h2];
	//	minutes += m2;
	//}
	return sum;
}

int main()
{
	int i, ret, n;
	for (i = 0; i < 24; ++i) {
		ret = scanf("%d", &tolls[i]);
	}
	string name, time, status;//分别表示名字，时间和on-line/off-line
	map<string, map<string, string>> records;
	ret = scanf("%d", &n);
	for (i = 0; i < n; ++i) {//存储数据
		cin >> name >> time >> status;
		auto it = records.find(name);
		if (it != records.end()) {
			it->second.insert(make_pair(time, status));
		}
		else {
			records[name][time] = status;
		}
	}
	vector<string> res;//存储结果
	string month, name2 = records.begin()->first;
	for (auto it = records.begin(); it != records.end(); ++it) {
		int sum_cost = 0;//每位用户总花费初始化为零
		month = it->second.begin()->first.substr(0, 2);
		res.push_back(it->first + " " + month);
		for (auto it2 = it->second.begin(); it2 != it->second.end();) {
			auto it3 = it2;
			++it3;
			if (it2->first.substr(0, 2) != month) {//若当前月份不等于前一月份
				month = it2->first.substr(0, 2);//month更新
				res.push_back(it->first + " " + month);
			}				
			if (it3 != it->second.end() && it2->second == "on-line" && it3->second == "off-line") {
				int minutes = 0;
				int cost = compute(it2->first, it3->first, minutes);
				int k = 0;
				string tmp = to_string((double)cost/100);
				for (k = 0; k < tmp.size() && tmp[k] != '.'; ++k);//找到.的位置，以便保留两位小数
				sum_cost += cost;//累加总费用
				if(cost > 0)
					res.push_back(it2->first.substr(3) + " " + it3->first.substr(3) + " " \
						+ to_string(minutes) + " $" + tmp.substr(0, k+3));
				++it2;
			}
			++it2;
			//当前月份不等于前一月份或者it2到达末尾则代表该用户当月话费已计算完毕
			if (it2 != it->second.end() && it2->first.substr(0, 2) != month || it2 == it->second.end()) {
				if (sum_cost > 0) {
					string tmp = to_string((double)sum_cost / 100);
					int k;
					for (k = 0; k < tmp.size() && tmp[k] != '.'; ++k);
					res.push_back("Total amount: $" + tmp.substr(0, k + 3));
				}					
				else res.pop_back();//如果用户当月未产生费用，则把用户信息删除
				sum_cost = 0;//以便进行下一轮计算
			}
		}		
	}
	for (const auto& item : res) {
		cout << item << endl;
	}
	return 0;
}