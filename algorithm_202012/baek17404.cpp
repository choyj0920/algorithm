// baek17404 RGB거리2

#include <iostream>
#include <limits.h>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int dp[1001][3][3];
const int INF =1000000;
int arr[1000][3];

int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    cin>>n;
    for (int i = 0; i < n ; i++){
        for(int j=0;j<3;j++)
            cin>>arr[i][j];
    }
    
    memset(dp,INF,sizeof dp);

    dp[0][0][0]= arr[0][0];
    dp[0][1][1]= arr[0][1];
    dp[0][2][2]= arr[0][2];

    for(int i=1;i<n-1;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                for (int z=0;z<3;z++){
                    if(j==z) continue;
                    dp[i][j][k]=min(dp[i][j][k],dp[i-1][z][k]+arr[i][j]);
                }
            }
        }
    }
    int min_value=INF;
    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            for (int z=0;z<3;z++){
                if(j==z || j==k) continue;
                min_value=min(min_value,dp[n-2][z][k]+arr[n-1][j]);
            }
        }
    }
    cout<<min_value;


}