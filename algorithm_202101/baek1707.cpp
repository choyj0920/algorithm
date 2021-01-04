// baek1707 이분 그래프
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int v,e;
vector<vector<int>>edges;
vector <int> visited;

int bfs(int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int current=q.front();
        q.pop();
        int currentcolor=visited[current];
        for (int next : edges[current]){
            if (visited[next]==0){
                visited[next]= -currentcolor;
                q.push(next);
            }
            else if (visited[next] == currentcolor){
                return false;
            }
        }
    }
    return true;   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;

    cin>>T;
    while ((T--))
    {
        cin>>v>>e;
        edges=vector<vector<int>>(v,vector<int>());
        visited=vector<int>(v,0);
        for (int i=0;i<e;i++){
            int a,b;
            cin>>a>>b;
            a--; b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        bool flag=true;
        for (int i=0;i<v;i++){
            if (visited[i]==0){
                flag=bfs(i);
                if (flag==false)
                    break;
                
            }
        }

        cout<<(flag?"YES":"NO")<<'\n';
    }
    

}