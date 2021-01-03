//baek17298 오큰수
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int arr[1000001],result[1000001];
int main(){
    int n;
    stack<int> s;
    cin>>n;
    for (int i=0;i<n;i++) 
        cin>>arr[i];

    for (int i =0 ;i<n;i++){
        while (!s.empty() && arr[s.top()] < arr[i]){
            result[s.top()] =arr[i];
            s.pop();
        }
        s.push(i);
        
    }
    for (int i=0;i<n;i++) cout<<(result[i]==0?-1:result[i])<<' ';
    cout<<'\n';


}