// baek11780 플로이드2

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

#define INF 1000001

using namespace std;

int edges[101][101];    // 
int via[101][101];      // 경유지 배열, 0이면 경유지 없음

void findpath(int start,int end,vector<int> &path){
    
    // 경유지가 없다면
    if (via[start][end] ==0){
        // 
        path.push_back(start);
        if (start != end){
            path.push_back(end);
        }
    }
    // 경유지가 있다면
    else{
        
        // 경유지 w
        int w=via[start][end];

        // start,w 로 재귀 호출
        findpath(start,w,path);
        //  w 경로 제거
        path.pop_back();
        // w, end 재귀
        findpath(w,end,path);

    }

}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;

    for (int i=1;i<=n;i++)
        for (int j =1 ;j<=n;j++)
            i==j ? edges[i][j]=0 :edges[i][j]=INF;
    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges[a][b]=min(edges[a][b],c);
        
    }

    // 플로이드 와샬 알고리즘
    // k 경유지
    for (int k =1; k<=n; k++)
        // i 시작지
        for (int i=1; i <= n; i++)
            // j 도착지
            for(int j=1; j<=n;j++){
                if(edges[i][j] > edges[i][k]+edges[k][j]){
                    via[i][j]=k;
                    edges[i][j]=edges[i][k]+edges[k][j];
                }
            }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++)
            cout<<edges[i][j]<<" ";
        cout<<'\n';
    }
    // 경로찾기
    vector<int>path;
    for(int i =1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if(i==j){
                cout<<"0\n";
                continue;
            }
            findpath(i,j,path);

            cout<<path.size()<<" ";
            for (int i=0; i<path.size();i++)
                cout<<path[i]<<" ";
            cout<<"\n";

            path.clear();
        }
    }

    
}


