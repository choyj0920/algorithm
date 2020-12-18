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

    for (int i=0;i<=n;i++){
        dp[i][1] =i;
        dp[i][0] = 1;
    }

    for (int i=2;i<=n;i++){
        for (int j=2;j<=k; j++){
            dp[i][j]=(dp[i-2][j-1]+dp[i-1][j]) % mod;
        }
    }
    int ans= (dp[n-1][k]+ dp[n-3][k-1]) % mod; //0과 n은 같이 색칠되면 안됨
    cout<<ans<<'\n';



}