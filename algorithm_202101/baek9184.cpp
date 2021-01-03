// baek9184 신나는 함수 실행
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int dp[21][21][21]={0,};
int w(int a,int b, int c){
    if (a<=0 || b<=0 || c<=0)
       return 1;    

    if (a>20 or b>20 or c> 20)
        return w(20,20,20);
        
    int& temp= dp[a][b][c];
    if (temp != 0)
        return temp;
    else if (a<b && b<c){
        temp=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
        return temp;
    }else{
        temp=w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1)-w(a-1,b-1,c-1);
        return temp;
    }
    

}

int main(){
    int a,b,c;
    while (1){
        cin>>a>>b>>c;
        if (a==-1 && b==-1 && c==-1) break;
        printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
    }

}