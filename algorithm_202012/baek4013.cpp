// baek4013 ATM

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
#include <deque>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int INF = 21 * 1e8;
const int MAX = 1e9;

int n,m;

vector<int> money;
vector<bool> rest;
vector<vector<int>> edge;
vector<int> discovered;
vector<vector<int>> scc;
vector<int> sccidx;
vector<bool> finished;
stack<int> st;
vector<int> earn;
vector<int> dp;

int s,P;
int discovcnt = 0;
int scccnt = 0;
int ans = 0;

int findscc(int cur)
{
   discovered[cur] = discovcnt++;
   int ret= discovered[cur];
   st.push(cur);

   for(auto next : edge[cur])
   {
       if(discovered[next] == -1)
       {
           ret= min(ret,findscc(next));
       }
       else if(!finished[next])
       {
           ret = min(ret,discovered[next]);
       }
   }    

   if(ret >= discovered[cur] && !finished[cur])
   {
       scc.push_back(vector<int>());
       while(1)
       {
           int stop = st.top();
           st.pop();

           money[scccnt] += earn[stop];
           sccidx[stop] = scccnt;
           scc[scccnt].push_back(stop);
           finished[stop] = true;

           if(stop == cur) break;
       }

       scccnt++;
   }

   return ret;
}

int main()
{
   ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
   cin>>n>>m;

   edge = vector<vector<int>>(n);
   rest = vector<bool>(n,false);
   discovered = vector<int>(n,-1);
   sccidx = vector<int>(n);
   finished = vector<bool>(n,false);
   earn = vector<int>(n,0);
   money = vector<int>(n,0);
   dp = vector<int>(n,0);
  
   for(int i = 0;i<m;i++)
   {
       int v1,v2;
       cin>>v1>>v2;
       v1--; v2--;
       edge[v1].push_back(v2);
   }

   for(int i = 0;i<n;i++)
   {
       cin>>earn[i];
   }

   cin>>s>>P;

   s--;

   for(int i = 0;i<P;i++)
   {
       int r;
       cin>>r;
       r--;

       rest[r] = true;
   }

   findscc(s);
   dp[scccnt-1] = money[scccnt-1];

   for(int i = scccnt-1;i>=0;i--)
   {
       for(auto elem : scc[i])
       {
           for(auto next : edge[elem])
           {
               if(sccidx[next] != i)
               {
                   dp[sccidx[next]] = max(dp[sccidx[next]],dp[i] + money[sccidx[next]]);
               }
           }
       }        
   }

   for(int i = 0;i<n;i++)
   {
       if(rest[i] && discovered[i] != -1)
       {
           ans = max(ans,dp[sccidx[i]]);
       }
   }

   cout<<ans;  

   return 0;
}