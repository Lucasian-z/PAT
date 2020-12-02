#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
//����ؼ��������ĳ��ĳ���޷��ò���������������û���Ϣ
int tolls[24] = { 0 };
int compute(string time1, string time2, int& minutes) {
	int d1 = stoi(time1.substr(3, 2)), h1 = stoi(time1.substr(6, 2)), m1 = stoi(time1.substr(9));
	int d2 = stoi(time2.substr(3, 2)), h2 = stoi(time2.substr(6, 2)), m2 = stoi(time2.substr(9));
	//cout << "h1 = " << h1 << " h2 = " << h2 << endl;
	int sum = 0;
	while (d1 != d2 || h1 != h2 || m1 != m2) {
		sum += tolls[h1];//�ۼӵ�ǰʱ��Ļ���
		++m1;//�ۼӷ�����
		++minutes;
		if (m1 == 60) {//Сʱ��+1
			++h1;
			m1 = 0;
		}
		if (h1 == 24) {//����+1
			++d1;
			h1 = 0;
		}
	}
	//�޴��İ취
	//if (d1 == d2) {//��ͬһ��
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
	//else {//����ͬһ��
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
	string name, time, status;//�ֱ��ʾ���֣�ʱ���on-line/off-line
	map<string, map<string, string>> records;
	ret = scanf("%d", &n);
	for (i = 0; i < n; ++i) {//�洢����
		cin >> name >> time >> status;
		auto it = records.find(name);
		if (it != records.end()) {
			it->second.insert(make_pair(time, status));
		}
		else {
			records[name][time] = status;
		}
	}
	vector<string> res;//�洢���
	string month, name2 = records.begin()->first;
	for (auto it = records.begin(); it != records.end(); ++it) {
		int sum_cost = 0;//ÿλ�û��ܻ��ѳ�ʼ��Ϊ��
		month = it->second.begin()->first.substr(0, 2);
		res.push_back(it->first + " " + month);
		for (auto it2 = it->second.begin(); it2 != it->second.end();) {
			auto it3 = it2;
			++it3;
			if (it2->first.substr(0, 2) != month) {//����ǰ�·ݲ�����ǰһ�·�
				month = it2->first.substr(0, 2);//month����
				res.push_back(it->first + " " + month);
			}				
			if (it3 != it->second.end() && it2->second == "on-line" && it3->second == "off-line") {
				int minutes = 0;
				int cost = compute(it2->first, it3->first, minutes);
				int k = 0;
				string tmp = to_string((double)cost/100);
				for (k = 0; k < tmp.size() && tmp[k] != '.'; ++k);//�ҵ�.��λ�ã��Ա㱣����λС��
				sum_cost += cost;//�ۼ��ܷ���
				if(cost > 0)
					res.push_back(it2->first.substr(3) + " " + it3->first.substr(3) + " " \
						+ to_string(minutes) + " $" + tmp.substr(0, k+3));
				++it2;
			}
			++it2;
			//��ǰ�·ݲ�����ǰһ�·ݻ���it2����ĩβ�������û����»����Ѽ������
			if (it2 != it->second.end() && it2->first.substr(0, 2) != month || it2 == it->second.end()) {
				if (sum_cost > 0) {
					string tmp = to_string((double)sum_cost / 100);
					int k;
					for (k = 0; k < tmp.size() && tmp[k] != '.'; ++k);
					res.push_back("Total amount: $" + tmp.substr(0, k + 3));
				}					
				else res.pop_back();//����û�����δ�������ã�����û���Ϣɾ��
				sum_cost = 0;//�Ա������һ�ּ���
			}
		}		
	}
	for (const auto& item : res) {
		cout << item << endl;
	}
	return 0;
}