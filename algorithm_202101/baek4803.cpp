// baek4803 트리
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
 
using namespace std;
 
int main()
{
    int n, m;
    int from, to, val;
    int tcase = 0;
    while (1)
    {
        scanf("%d %d", &n, &m);
 
        if (n == 0 && m == 0)
            return 0;
 
        vector<int> vc[1002];
        queue<int> q;
        bool visited[1002];
 
        fill(visited, visited + 1002, false);
 
        int cnt = 0;
 
        while (m--)
        {
            scanf("%d %d", &from, &to);
            
            vc[from].push_back(to);
            vc[to].push_back(from);
        }
 
        // 하나의 노드 혹은 사이클에 대해 V, E를 알 수 있게 된다.
        for (int i = 1; i <= n; i++)
        {
            // 방문한 적 없는 노드는 방문
            // (cnt에 의해 연결 요소의 개수가 정해진다.)
            // (연결 요소의 개수 :: 트리 + 사이클)
            int edge = 0;
            int vertex = 0;
            if (visited[i] == false)
            {
                cnt++;
 
                q.push(i);
 
                while (!q.empty())
                {
                    int here = q.front();
                    q.pop();
 
                    // 이 조건문을 통해 정점의 개수를 알 수 있다.
                    // 방문한 적이있는 정점이면 정점에 추가 해주지 않는다는 것
                    if (visited[here])
                        continue;
 
                    vertex++;
                    visited[here] = true;
 
                    // 양방향 그래프의 간선이 추가된다.
                    for (int j = 0; j < vc[here].size(); j++)
                    {
                        edge++;
                        q.push(vc[here][j]);
                    }
                }
                
                // 트리이기 위해서는 '간선 / 2 == 정점 - 1' 이어야 한다.
                if (edge / 2 != vertex - 1)
                    cnt--;
 
                edge = 0;
                vertex = 0;
            }
        }
 
 
        if (cnt >= 2)
            printf("Case %d: A forest of %d trees.\n", ++tcase, cnt);
        else if (cnt == 1)
            printf("Case %d: There is one tree.\n", ++tcase);
        else
            printf("Case %d: No trees.\n", ++tcase);
    }
 
    return 0;
}
 

