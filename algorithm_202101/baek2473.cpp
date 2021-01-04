// baek2473 두 용액

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll  arr[100001]={0,};
int n;
int main(){
    cin>>n;
    for (int i=0; i<n;i++)
        cin>>arr[i];
        
    sort(arr,arr+n);
    ll minvalue=2000000000;
    int front=0,back=n-1;
    int minfront,minback;
    while (front<back){
        ll temp=arr[front]+arr[back];
        if(llabs(temp)<minvalue){
            minvalue=llabs(temp);
            minfront=front; minback=back;
        }
        if (temp<0)
            front++;
        else
            back--;
    }
    cout<<arr[minfront]<<" "<<arr[minback]<<'\n';


}
