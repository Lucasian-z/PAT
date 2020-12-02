#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100;
int N, M, S;
//struct node {
//	int weight, father = -1;
//	vector<int> child;
//}Node[maxn];
//
//bool isEqualSum(int id) {
//	int sum = 0;
//	while (Node[id].father != -1) {
//		sum += Node[id].weight;
//		//cout << "sum = " << sum << endl;
//		if (sum > S)
//			return false;
//		id = Node[id].father;
//	}
//	sum += Node[id].weight;
//	if (sum != S)
//		return false;
//	return true;
//}
//
//bool cmp(vector<int> a, vector<int> b) {
//	for (int i = 0; i < a.size() && i < b.size(); ++i) {
//		if (a[i] != b[i])
//			return a[i] > b[i];
//	}
//	return a.size() > b.size();
//}
//
//int main()
//{	
//	int ret = scanf("%d %d %d", &N, &M, &S);
//	int i;
//	for (i = 0; i < N; ++i) {
//		ret = scanf("%d", &Node[i].weight);
//	}
//	int Id, k, id;
//	for (i = 0; i < M; ++i){
//		ret = scanf("%d %d", &Id, &k);
//		for (int j = 0; j < k; ++j) {
//			ret = scanf("%d", &id);
//			Node[Id].child.push_back(id);
//			Node[id].father = Id;
//		}
//	}
//	vector<vector<int>> ans;
//	for (i = 0; i < N; ++i) {
//		vector<int> res;
//		if (!Node[i].child.size()) {
//			//cout << "i = " << i << endl;
//			if (isEqualSum(i))
//			{
//				//cout << "i2 = " << i << endl;
//				int j = i;
//				while (Node[j].father != -1)
//				{
//					res.push_back(Node[j].weight);
//					j = Node[j].father;
//				}
//				res.push_back(Node[j].weight);
//				reverse(res.begin(), res.end());
//				ans.push_back(res);				
//			}
//		}
//	}
//	sort(ans.begin(), ans.end(), cmp);
//	for (i = 0; i < ans.size(); ++i) {
//		int len = ans[i].size();
//		for (auto j = 0; j < len; ++j) {
//			if (j != 0)
//				printf(" ");
//			printf("%d", ans[i][j]);
//			if (j == len-1) printf("\n");
//		}
//	}
//	return 0;
//}

//更简洁的一种方法
struct node {
	int weight;
	vector<int> child;
}Node[maxn];
int path[maxn];

bool cmp(int a, int b){
	return Node[a].weight > Node[b].weight;
}

void DFS(int index, int nodenum, int sum) {
	if (sum > S) return;
	if (sum == S) {
		if (!Node[index].child.empty()) return;
		else {
			for (int i = 0; i <nodenum; ++i) {
				printf("%d", Node[path[i]].weight);
				if (i < nodenum - 1) printf(" ");
				else if (i == nodenum - 1) printf("\n");
			}
			return;
		}
	}
	for (int i = 0; i < Node[index].child.size(); ++i) {
		int child = Node[index].child[i];
		path[nodenum] = child;
		DFS(child, nodenum + 1, sum + Node[child].weight);
	}
}

int main()
{
	int ret = scanf("%d %d %d", &N, &M, &S);
	int i, id, k, child;
	for (i = 0; i < N; ++i)
		ret = scanf("%d", &Node[i].weight);
	for (i = 0; i < M; ++i) {
		ret = scanf("%d %d", &id, &k);
		for (int j = 0; j < k; ++j) {
			ret = scanf("%d", &child);
			Node[id].child.push_back(child);
		}			
		sort(Node[id].child.begin(), Node[id].child.end(), cmp);
	}
	path[0] = 0;
	DFS(0, 1, Node[0].weight);
	return 0;
}