// baek11281 2-SAT-4
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,n) for(int i=1;i<=n;++i)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
using namespace std;
 
#define T(x) (x<<1)
#define F(x) (x<<1|1)
 
int n, m, a, b, VC, SC;
 
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
    adj.resize(n << 1);
    discovered.clear();
    sccid.clear();
    discovered = sccid = vector<int>(n << 1, -1);

    while (m--) { // 심사위원 심사 입력
        cin >> a >> b;
        a = a > 0 ? T(a - 1) : F(~a);
        b = b > 0 ? T(b - 1) : F(~b);
        OR(a, b);
    }

    rep(i, n << 1) if (discovered[i] == -1) scc(i); // scc 수행

    for (int i = 0;i < n;++i) if (sccid[i] == sccid[i ^ 1]) {   // 한 그룹안에 참 거짓 존재 바로 사형
        cout<<"0\n";
        return 0;
    }
    cout<<"1\n";
    for (int i=1;i<=n;i++){
        int k=(i-1)<<1;
        cout<<(sccid[k]<sccid[k^1]?"1":"0")<<" "; // 위상정렬 순서에 따라 판별
    }
 
 
    return 0;
}