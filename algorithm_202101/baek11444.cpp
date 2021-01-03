// baek11444 피보나치수6
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#define mod 1000000007

using namespace std;
typedef long long ll;

map<ll,ll> m;


ll solve(ll n){
    if (n==1 || n==2)
        return 1;
    if (m[n])
        return m[n];
    if (n % 2 == 1){
        ll t= (n+1)/2;
        ll fn=solve(t);
        ll fn1=solve(t-1);

        m[n]= (fn*fn+fn1*fn1) % mod;
        return m[n];
    }
    else {
        ll t= n/2;
        ll fn=solve(t);
        ll fn1=solve(t-1);

        m[n]= (fn+fn1*2)*fn % mod;
        return m[n];

    }
    
    
}

int main(){
    ll n;
    cin>>n;
    cout<<solve(n)<<'\n';
}
