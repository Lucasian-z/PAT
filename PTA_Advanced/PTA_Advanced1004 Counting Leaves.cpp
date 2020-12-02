#include <iostream>
#include <map>
using namespace std;

int main()
{
    int node_child_level[100][2] = {0}; //下标表示节点值，是否有孩子和所处层
    int N, M, K, i, j, Id, id;
    cin >> N >> M;
    map<int,int>res;
    if(!M)
    {
        printf("%d", N);
        return 0;
    }
    for(i = 0; i < M; ++i)
    {
        scanf("%d %d", &Id, &K);
        node_child_level[Id][0] = 1;
        if(!i)
            node_child_level[Id][1] = 1;
        for(j = 0; j < K; ++j)
        {
            scanf("%d", &id);
            node_child_level[id][1] = node_child_level[Id][1] + 1;
        }
    }
    for(i = 0; i < 100; ++i)
    {
        if(node_child_level[i][0] == 0 && node_child_level[i][1])
        {
            ++res[node_child_level[i][1]];
        }
    }
    auto end = --res.end();
    for(i = 1; i <= end->first; ++i)
    {
        if(i != 1)
            printf(" ");
        if(res.find(i) != res.end())
            printf("%d", res[i]);
        else printf("0");
    }
    return 0;
}
