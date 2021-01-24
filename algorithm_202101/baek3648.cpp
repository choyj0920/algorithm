// baek3648 아이돌
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
using namespace std;
typedef pair<int,int> P;
const int MAX = 1001;  // n변수 최대 값

int N,M, cnt,scc,dfsn[MAX*2],sccidx[MAX*2];
vector<int> edge[MAX*2];
bool finished[MAX*2];
stack<int> st;

// 자신의 not literal의 정점 번호 리턴 +,- 전환
inline int oppo(int n) {return n%2? n-1:n+1;}

int findscc(int cur)
{
   dfsn[cur] = ++cnt;
   int ret= dfsn[cur];
   st.push(cur);

   for(auto next : edge[cur])
   {
       if(dfsn[next] == 0) // 아직 방문 x
       {
           ret= min(ret,findscc(next));
       }
       else if(!finished[next]) // 
       {
           ret = min(ret,dfsn[next]);
       }
   }    

   if(ret >= dfsn[cur] && !finished[cur])
   {
       while(1)
       {
           int stop = st.top();
           st.pop();
           sccidx[stop] = scc;
           finished[stop] = true;
           if(stop == cur) break;
       }
       scc++;
   }

   return ret;
}
int main(){
    //input
    FAST;
    while(cin>>N>>M){
        cnt=0;
        memset(dfsn,0,N<<1);
        memset(finished,false,N<<1);
        memset(sccidx,0,N<<1);
        edge->clear();
        edge->resize(N<<1);
        st=stack<int>();
        scc=0;
        for (int i =0; i<M;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            a = (a<0? -(a+1)*2 : a*2-1);
            b = (b<0? -(b+1)*2 : b*2-1);
            edge[oppo(a)].push_back(b);
            edge[oppo(b)].push_back(a);        
        }

        // scc
        for (int i=0; i<N*2;i++){
            if (dfsn[i]==0) findscc(i);
        }
        bool flag=true;
        for (int i =0;i<N;i++){
            if (sccidx[i*2]==sccidx[i*2+1]){    //불 가능
                flag=false;
                break;
            }
        }
        if (sccidx[1]<sccidx[oppo(1)]){
            flag=false;
        }

        cout<<(flag?"yes":"no")<<'\n';
    }



}