// baek1806 부분합


#include <iostream>
#include <algorithm>

using namespace std;

int  arr[100001]={0,};
int n,s;
int main(){
    cin>>n>>s;
    for (int i=1; i<=n;i++)
        cin>>arr[i];
        
    for (int i=2; i<=n;i++)
        arr[i]+=arr[i-1];

    
    for (int i=1;i<=n;i++){
        for(int j=0;j+i<=n;j++)
            if((arr[j+i]-arr[j])>=s){
                cout<<i<<" ";
                return 0;
            }
    }

    cout<<0<<'\n';


}
