// baek1644 소수의 연속합

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<int> primes;
vector<bool> check;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    //에라토스테네스의 체
    check.resize(n+1,true);
    
    for (int i=2;i*i<=n;i++){
        if (!check[i]) continue;
        for (int j=i*i; j<=n;j+=i){
            check[j]=false;
        }
    }
    for(int i=2;i<=n;i++){
        if (check[i]) primes.push_back(i);
    }

    int result=0,sum=0,front=0,end=0;
    while (1)
    {
        if(sum>=n){
            sum-=primes[front++];
        }
        else if (end==primes.size())
            break;
        else
            sum+=primes[end++];
        
        if(sum==n) result++;
        
    }
    cout<<result;

}