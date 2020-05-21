#include<cstdio>
#include<cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define MAXN 200010
#define INF 1000000000

int d1[MAXN], d2[MAXN];
int h[MAXN];
int head[MAXN];
int p[MAXN];
set <int> s;
vector <int> ans;
struct edge { int v; int next; };
edge G[MAXN * 2];
int num = 0;
int vis[MAXN];
void add(int u, int v) { G[num].v = v; G[num].next = head[u]; head[u] = num++; };
void dfs(int u, int d[])
{
    vis[u] = true;
    for (int k = head[u]; k != -1; k = G[k].next) {
        int v = G[k].v;
        if (!vis[v]) {
            d[v] = d[u] + 1;
            dfs(v, d);
        }
    }
}
int n, m, d;
int main() {
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 0; i < m; i++) {
        scanf("%d", p + i);
        s.insert(p[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (s.count(i) == 0)
            ans.push_back(i);
    }
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    h[1] = 0;
    dfs(1, h);
    int max1 = 0;
    for (int i = 0; i < m; i++) {
        if (h[p[i]] > h[p[max1]])
            max1 = i;
    }
    memset(vis, 0, sizeof(vis));
    d1[p[max1]] = 0;
    dfs(p[max1], d1);
    int max2 = 0;
    for (int i = 0; i < m; i++) {
        if (d1[p[i]] > d1[p[max2]])
            max2 = i;
    }
    memset(vis, 0, sizeof(vis));
    d2[p[max2]] = 0;
    dfs(p[max2], d2);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (d1[i] <= d && d2[i] <= d)
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}