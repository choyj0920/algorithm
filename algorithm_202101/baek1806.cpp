// baek1806 부분합


#include <iostream>
#include <algorithm>

using namespace std;

int  arr[100001]={0,};
int n,s;
int main(){
    cin>>n>>s;
    for (int i=0; i<n;i++)
        cin>>arr[i];
        
    int start=0,end=0,sum=0,minLen=100010;
    while (start<=end)
    {
        if(sum>=s){
            minLen=min(minLen,end-start);
            sum-= arr[start++];
        }
        else if (end==n) break;
        else sum += arr[end++];
    }
    cout<<(minLen==100010?0:minLen)<<"\n";

}
