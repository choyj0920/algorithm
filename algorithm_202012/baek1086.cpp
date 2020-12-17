// baek 1086 박성원
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string s[16];
int arr[16],len[16];            // 나머지 배열 담을 배열, 각 원소의 길이 담을 배열
ll dp[1 << 15][111];
int N,K;
int pw[55];

ll f(int bit, int md){
    ll& res = dp[bit][md];      //bit 사용여부, md는 나머지 dp[][]=경우의수
    if(res != -1) return res;   //이미 도달한경우(dp[bit][md]가 초기화상태가 아님) 반환

    if(bit + 1 == 1 << N){  //모든 원소를 다 포함했을 경우
        if(md) return  res=0;   // 나머지가 0이 아니면 res 0 카운트x
        else return res=1;      // 나머지가 0이면 res 1 카운트o
    }
    res=0;
    for(int i = 0; i < N ; i++){
        if(!(bit & (1 << i))){
            int t = md *pw[len[i]] +arr[i];     // 이전 수열뒤에arr[i] 추가  이전수열 *칸수(나머지) + arr[i](나머지)
            res += f(bit | (1<<i),t % K);       // 다음 함수 실행
        }
    }
    return res;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 입력 
    cin>>N;
    for (int i =0; i<N ;i++){
        cin>>s[i];
    }
    cin>>K;

    // 값 나머지만 담기
    for (int i = 0; i < N ; i++){
        len[i]=s[i].size();
        int t=0;
        for(auto c: s[i]){ 
            t*=10; t%=K;
            t += c -'0'; t %= K;
        }
        arr[i]=t;
    }
    memset(dp,-1,sizeof dp);
    pw[0] = 1 % K;
    for(int i=1; i<55 ; i++) pw[i]= pw[i-1]* 10 % K;
    ll p = f(0,0), q= 1; // p는 나누어지는 경우 q는 총 경우의 수
    if(p==0){
        cout<<"0/1"; return 0;
    }
    for(int i=1;i<=N;i++) q *=i;    // 총 경우의 수
    ll g=__gcd(p,q);                // 최대 공약수 
    p/=g; q/=g;
    cout<<p<<'/'<<q<<'\n';          //기약분수출력


    


}