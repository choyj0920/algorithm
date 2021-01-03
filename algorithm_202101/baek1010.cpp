// baek1010 다리 놓기
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin>>T;
    int arr[31][31]={0,};

    for (int i=0; i<=30;i++){
        for (int j=0; j<=i;j++){
            if (i== j || j==0)
                arr[i][j]=1;
            else
                arr[i][j] = arr[i-1][j-1]+ arr[i-1][j];
        }
    }



    while (T--){
        int a,b;
        cin>>a>>b;
        cout<<arr[b][a]<<'\n';
    }
}