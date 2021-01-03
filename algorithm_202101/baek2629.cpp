// baek2629 양팔저울
#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
# define MAX 30

using namespace std;

int sinkernum,marblenum;
vector <int> weight;
vector <int> marble;
bool dp[MAX+1][MAX*500+1];

void solve(int currentMarble, int currentWeight){
    if (currentMarble> sinkernum)
        return;
    if (dp[currentMarble][currentWeight])
        return;
    
    dp[currentMarble][currentWeight]=true;

    // 이번 추를 구슬 반대 쪽에 달았을 때
    solve(currentMarble+1, currentWeight+ weight[currentMarble]);
    // 이번 추를 구슬 쪽에 달았을 때
    solve(currentMarble+1, abs(currentWeight-weight[currentMarble]));
    // 이번 추를 달지 않았을 때
    solve(currentMarble+1,currentWeight);
    
}

int main(){
    cin>> sinkernum;
    for (int i =0; i< sinkernum;i++){
        int sinkerweight; cin>> sinkerweight;
        weight.push_back(sinkerweight);
    }
    cin>>marblenum;
    for (int i=0; i< marblenum;i++){
        int marbleweight; cin>> marbleweight;
        marble.push_back(marbleweight);
    }

    solve(0,0);
    
    for (int i=0;i<marblenum;i++) {
        if (marble[i]>MAX*500) {
            cout<<"N ";
            continue;
        }
        cout<<((dp[sinkernum][marble[i]]?"Y ":"N "));
    }
    

}

