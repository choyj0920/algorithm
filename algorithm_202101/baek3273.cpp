// baek3273 두 수의 합

#include <iostream>
#include <algorithm>
using namespace std;
int  arr[100001]={0,};
int n,x;
int main(){
    cin>>n;
    for (int i=0; i<n;i++)
        cin>>arr[i];
    cin>>x;
    sort(arr,arr+n);
    int front=0,back=n-1, cnt=0;
    while (front<back){
        int temp=arr[front]+arr[back];
        if (temp<x)
            front++;
        else if(temp>x)
            back--;
        else{
            front++;
            cnt++;
        }
    }
    cout<<cnt<<'\n';


}
