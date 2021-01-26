// baek16367 TV Show Game
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,n) for(int i=1;i<=n;++i)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
using namespace std;
 
#define T(x) (x<<1)
#define F(x) (x<<1|1)
 
int n, m, a, b,c, VC, SC;
 
vector<vector<int>> adj; // 간선 정보
vector<int> discovered, sccid; // 
stack<int> st;
int scc(int here) {     // scc함수 
    int ret = discovered[here] = VC++; //정점고유id
    st.emplace(here);
 
    for (auto there : adj[here]) {
        if (discovered[there] == -1) ret = min(ret, scc(there)); //아직 발견안한 노드 scc
        else if (sccid[there] == -1) ret = min(ret, discovered[there]); // 발견한노드 부모 혹은 형제
    }
 
    if (ret == discovered[here]) { //부모노드면
        while (1) {// st 나올때까지
            int t = st.top();   
            st.pop();
            sccid[t] = SC; // 그룹 id
            if (t == here) break; //부모노드(자신)나올 떄 가지
        }
        SC++; //그룹id
    }
    return ret;
}
 
void OR(int A, int B) {
    adj[A ^ 1].emplace_back(B);
    adj[B ^ 1].emplace_back(A);
}
 
int main() {
    FAST;
    cin >> n >> m;
    VC = SC = 0;
    adj.clear();
    adj.resize(n*3+1);
    discovered.clear();
    sccid.clear();
    discovered = sccid = vector<int>(n *3, -1);
    char ac,bc,cc;
    int temp[3]={0,};
    int tempcolor[3]={};
    char _temp; 
    while (m--) { // 심사위원 심사 입력

        for (int i=0;i<3;i++){
            cin>>temp[i]>>_temp;
            if (_temp=='R') tempcolor[i]=0;
            else if (_temp=='G') tempcolor[i]=1;
            else tempcolor[i]=2;
        }
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                if (tempcolor[i] != j){
                    adj[(temp[i]-1)*3+j].emplace_back((temp[(i+1)%3]-1)*3+tempcolor[(i+1)%3]);
                    adj[(temp[i]-1)*3+j].emplace_back((temp[(i+2)%3]-1)*3+tempcolor[(i+2)%3]);

                }
            }
        }
    }

    rep(i, n *3) if (discovered[i] == -1) scc(i); // scc 수행

    for (int i = 0;i < n;++i) if (sccid[i*3] == sccid[i*3+1] || sccid[i*3] == sccid[i*3+2] || sccid[i*3+1]==sccid[i*3+2]) {   // 한 그룹안에 참 거짓 존재 바로 사형
        cout<<"-1\n";
        return 0;
    }
    for (int i=0;i<n;i++){
        int r=sccid[i*3],g=sccid[i*3+1],b=sccid[i*3+2];
        if (r<g && r<b){
            cout<<'R';
            continue;
        }else if(g<b){
            cout<<'G';
            continue;
        }else{
            cout<<'B';
            continue;
        }


    }
    cout<<'\n';
 
 
    return 0;
}