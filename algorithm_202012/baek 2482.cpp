// baek 2482  색상환

#include <iostream>
#include <limits.h>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
const int mod=1000000003;


int n,k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    cin>>n>>k;

    for (int i=0;i<=n;i++){  // 값 초기화 
        dp[i][1] =i;
        dp[i][0] = 1;
    }

    for (int i=2;i<=n;i++){ //2칸 2개색칠 부터 -여기에선 선형적으로  원형이라는걸 무시
        for (int j=2;j<=k&&j<=i; j++){
            dp[i][j]=(dp[i-2][j-1]+dp[i-1][j]) % mod;       //i칸중 j칸을 색칠하는 경우는 
                                                            //0~ i-1칸중 j칸을 색칠하는 경우 +  0~i-2칸중 j-1칸을 색칠하는(i칸색칠) 경우           
        }
    }
    int ans= (dp[n-1][k]+ dp[n-3][k-1]) % mod; //0과 n은 같이 색칠되면 안됨 -원형
    cout<<ans<<'\n';



}