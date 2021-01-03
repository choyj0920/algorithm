// baek13305 주유소
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int arr[100001],oil[100001];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<n;i++) cin>>arr[i];
    for (int i=0;i<n;i++) cin>>oil[i];
    
    int answer=0;
    int minoil=1000000000;
    for (int i=0;i<n-1;i++){
        minoil=min(minoil,oil[i]);
        answer += (minoil*arr[i+1]);
    }
    cout<<answer<<'\n';
}