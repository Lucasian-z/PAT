#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
using namespace std;

const int maxn = 510, INF = 0x3fffffff;//��������������
int G[maxn][maxn], cost[maxn][maxn];//�ֱ����·�̺ͻ���
int visit[maxn] = { 0 };
int dis[maxn] = { 0 };
int Pre[maxn], c[maxn];//�ֱ����ǰ����㣬��С����
int n;//�����ܽ����
void Dijkstra(int s) {
	fill(dis, dis + maxn, INF);//�����ʼ��Ϊ�����
	dis[s] = 0;
	for (int i = 0; i < n; ++i) Pre[i] = i;
	for (int i = 0; i < n; ++i) {
		int u = -1, MIN = INF;
		for (int v = 0; v < n; ++v) {
			if (visit[v] == 0 && dis[v] < MIN) {//�ҵ���С�����Ӧ�Ľ��
				u = v;
				MIN = dis[v];
			}
		}
		if (u == -1) return;
		visit[u] = 1;
		for (int v = 0; v < n; ++v) {
			if (visit[v] == 0 && G[u][v] != INF) {
				if (dis[v] > dis[u] + G[u][v]) {
					Pre[v] = u;//ǰһ���
					dis[v] = dis[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
				}
				else if (dis[v] == dis[u] + G[u][v] && c[u] + cost[u][v] < c[v]) {
					Pre[v] = u;
					c[v] = c[u] + cost[u][v];
				}
			}
		}
	}
}

void DFS(int s, int v) {//��ӡ���·��
	if (s == v) {
		printf("%d ", s);
		return;
	}
	DFS(s, Pre[v]);
	printf("%d ", v);
}

int main()
{
	int m, s, d, c1, c2, distance, spends;
	int ret = scanf("%d %d %d %d", &n, &m, &s, &d);
	fill(G[0], G[0] + maxn * maxn, INF);
	for (int i = 0; i < m; ++i) {
		ret = scanf("%d %d %d %d", &c1, &c2, &distance, &spends);
		G[c1][c2] = G[c2][c1] = distance;
		cost[c1][c2] = cost[c2][c1] = spends;
	}
	Dijkstra(s);
	DFS(s, d);
	printf("%d %d", dis[d], c[d]);
	return 0;
}