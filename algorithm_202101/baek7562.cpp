// baek7562 나이트의 이동

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int,int> p;
int _move[8][2]={{-2,1},{-1,2},{1,2},{2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int n;
int destx,desty;
int bfs(int x, int y){
    queue<p> q;
    q.push(p(x,y));
    vector < vector <int> > visited(n,vector <int>(n,0));
    visited[x][y]=1;
    if (x==destx && y==desty)
        return 0;
    while(!q.empty()){
        p current=q.front();
        q.pop();
        int currentcnt=visited[current.first][current.second];
        for (int i=0; i<8 ; i++){
            int nextx=current.first+ _move[i][0];
            int nexty=current.second+_move[i][1];
            if (0<=nextx && nextx<n && 0<=nexty && nexty<n){
                if (visited[nextx][nexty]==0){
                    q.push(p(nextx,nexty));
                    visited[nextx][nexty]=currentcnt+1;
                    if (destx==nextx && desty==nexty){
                        return currentcnt;
                    }
                }
            }
        }
    }
    return -1;   
}

int main(){
    int T,startx,starty;

    cin>>T;
    while ((T--))
    {
        cin>>n;
        cin>>startx>>starty;
        cin>>destx>>desty;

        cout<<bfs(startx,starty)<<'\n';
    }
    

}