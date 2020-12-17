// baek 2098 외판원 순회
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <string>
using namespace std;

int n, MASK_ALL;
int w[16][16]={0,};
int dp[16][1<<16]={0,}; //현재 위치와 지나온 도시마스크 dp[][]= 여기까지의 비용
int INF = 987654321;

int solution(int cur,int mask){
    if (mask==MASK_ALL){ //모든 도시 방문
        if(w[cur][0]==0){  // 이도시에서는 0으로 갈수 없다. 
            return INF;
        }
        else  // 0으로 갈수있음 cur->0 비용 리턴
            return w[cur][0];
    }

    int& ref = dp[cur][mask]; //0-> cur 까지 mask도시를 방문한 비용 ref
    if (ref != 0) // 먼저온 최적경로가 있다면 이미 연산 되었으니 리턴
        return ref;
    int m = INT_MAX - 16000001;
    for (int i=1;i< n; i++){  //아직 방문하지 않은 도시 반복문
        if(((mask&(1<<i))==0)&&(w[cur][i] !=0)) // 방문하지 않았다면 
            m = min(m,solution(i,( mask | (1<<i)))+ w[cur][i]); // 방문하지 않은 도시만 방문 
    }

    return ref=m; //참조 값 ref에 m 저장후 리턴

}


int main(){
    cin>> n;
    for (int i=0; i < n;i++)
        for (int j=0; j<n; j++)
            cin>>w[i][j];
    MASK_ALL=(1<<n)-1; // 모든 도시를 방문 했을 때 마스크 설정

    cout<<solution(0,1)<<'\n';


}