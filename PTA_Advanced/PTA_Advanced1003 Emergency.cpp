//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <utility>//fill所在头文件
//using namespace std;
//
//const int maxn = 500;//最大城市数量
//const int INF = 0x3fffffff;//无穷大
//int G[maxn][maxn];//邻接矩阵存储
//int visit[maxn] = { 0 };
//int num[maxn] = { 0 };
//int rescueTeamCnt[maxn], dis[maxn], w[maxn] = { 0 };
//int n, m;//城市数目和道路数目
//
//void Dijkstra(int s) {
//	fill(dis, dis + maxn, INF);//将距离初始化为无穷大
//	dis[s] = 0;
//	num[s] = 1;
//	w[s] = rescueTeamCnt[s];
//	for (int i = 0; i < n; ++i) {
//		int u = -1, MIN = INF;
//		for (int v = 0; v < n; ++v) {
//			if (visit[v] == 0 && dis[v] < MIN) {
//				u = v;
//				MIN = dis[v];
//			}
//		}
//		if (u == -1) return;
//		visit[u] = 1;
//		for (int i = 0; i < n; ++i) {
//			if (visit[i] == 0 && G[u][i] != INF) {
//				if (dis[i] > dis[u] + G[u][i]) {
//					dis[i] = dis[u] + G[u][i];
//					num[i] = num[u];//若u加入后dis[i]减小，说明dis[i]非最短路径，所以赋值为num[u]
//					w[i] = w[u] + rescueTeamCnt[i];
//				}
//				else if (dis[i] == dis[u] + G[u][i]) {
//					if (w[u] + rescueTeamCnt[i] > w[i])
//						w[i] = w[u] + rescueTeamCnt[i];
//					num[i] += num[u];//若u加入后，dis[i]不变，说明dis[i]和dis[u]位于不同最短路径，num[i]累加
//				}					
//			}
//		}
//	}
//}
//
//int main()
//{
//	int currCity, emerCity, i, city1, city2, length;
//	int ret = scanf("%d %d %d %d", &n, &m, &currCity, &emerCity);
//	fill(G[0], G[0] + maxn * maxn, INF);//邻接矩阵初始化为无穷大
//	for (i = 0; i < n; ++i) {
//		ret = scanf("%d", &rescueTeamCnt[i]);
//	}
//	for (i = 0; i < m; ++i) {
//		ret = scanf("%d %d %d", &city1, &city2, &length);
//		G[city1][city2] = length;
//		G[city2][city1] = length;
//	}
//	Dijkstra(currCity);
//	printf("%d %d", num[emerCity], w[emerCity]);
//	return 0;
//}

//Bellman_Ford算法
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct node {
	int v, dis;
	node(int _v, int _dis) :v(_v), dis(_dis) {}
};
const int maxn = 510, INF = 0x3fffffff;
vector<node> Adj[maxn];
int n, m, st, ed, weight[maxn];
int num[maxn], dis[maxn], w[maxn];
set<int> pre[maxn];

void Bellman(int s) {
	fill(dis, dis + maxn, INF);
	num[s] = 1;
	w[s] = weight[s];
	dis[s] = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (int u = 0; u < m; ++u) {
			for (int j = 0; j < Adj[u].size(); ++j) {
				int v = Adj[u][j].v;
				int d = Adj[u][j].dis;
				if (dis[u] + d < dis[v]) {
					dis[v] = d + dis[u];
					w[v] = w[u] + weight[v];
					num[v] = num[u];
					pre[v].clear();
					pre[v].insert(u);
				}
				else if (dis[u] + d == dis[v]) {
					if (w[u] + weight[v] > w[v])
						w[v] = w[u] + weight[v];
					pre[v].insert(u);
					num[v] = 0;
					for (auto it = pre[v].begin(); it != pre[v].end(); ++it) {
						num[v] += num[*it];
					}
				}
			}
		}
	}
}

int main()
{
	int ret = scanf("%d %d %d %d", &n, &m, &st, &ed);
	for (int i = 0; i < n; ++i) {
		ret = scanf("%d", &weight[i]);
	}
	int u, v, len;
	for (int i = 0; i < m; ++i) {
		ret = scanf("%d %d %d", &u, &v, &len);
		Adj[u].push_back(node(v, len));
		Adj[v].push_back(node(u, len));
	}
	Bellman(st);
	printf("%d %d", num[ed], w[ed]);
	return 0;
}