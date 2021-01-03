// baek13305 주유소
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll ;

ll arr[100001],oil[100001];
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n-1;i++) cin>>arr[i];
    for (int i=0;i<n;i++) cin>>oil[i];
    
    ll answer=oil[0]*arr[0];
    ll minoil=oil[0];
    for (int i=1;i<n;i++){
        minoil=min(minoil,oil[i]);
        answer += (minoil*arr[i]);
    }
    cout<<answer<<'\n';
}