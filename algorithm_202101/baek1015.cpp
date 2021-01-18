// baek1015 수열 정렬

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    pair<int,int> arr[n]={{0,0},};
    
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr[i]={temp,i};
    }
    sort(arr,arr+n);
    int a[n]={0,};

    for(int i=0;i<n;i++){
        a[arr[i].second]=i;
    } 
    for (int i=0; i<n;i++)
        cout<<a[i]<<' ';

     
    
}