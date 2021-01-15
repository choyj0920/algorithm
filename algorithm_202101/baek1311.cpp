// baek1311 할 일 정하기1
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <bitset>
using namespace std;

#define MAX_N 20
int dp[MAX_N][(1<<MAX_N)]={0,};
int arr[MAX_N][MAX_N]={0,};

int main(){
    
    int n;
    cin>>n;

    for (int i=0;i<n;i++){
        for (int j =0; j<n;j++)
            cin>>arr[i][j];
    }
    for(int i=0; i<n;i++){
        dp[0][(1<<i)]=arr[i][0];
    }
    
    for (int i=1;i<n;i++){
        for (int j=0; j<(1<<n);j++){
            if (dp[i-1][j]==0) continue;
            for (int k =0;k<n;k++){
                if((j&(1<<k))>>k) continue;
                if(dp[i][(j|(1<<k))]==0)
                    dp[i][(j|(1<<k))]=dp[i-1][j]+arr[k][i];
                else
                    dp[i][(j|(1<<k))]=min(dp[i][(j|(1<<k))],dp[i-1][j]+arr[k][i]);
            }
        }
    }
    cout<<dp[n-1][(1<<n)-1]<<endl;


    return 0;
}