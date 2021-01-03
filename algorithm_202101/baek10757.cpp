// baek10757 큰수 A+B

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string a,b;

    cin>>a>>b;
    
    if (a.size() > b.size()){  // a가 더 자리수 크면 b앞에 0
        string c;
        for (int i=0; i< a.size()-b.size();i++)
            c+='0';
        b=c+b;
    }
    else {
        string c;
        for (int i=0; i< b.size()-a.size();i++)
            c+='0';
        a=c+a;
    }

    int carry=0;
    string ans="";
    while(a.size()!=0 && b.size() != 0){
        int aback=a.back() - '0';
        int bback=b.back() - '0';
        int s= aback+bback+carry;         // 자릿수
        carry=s/10;
        s %=10;
        ans= (char)(s+'0')+ans;
        a.pop_back();
        b.pop_back();

    }

    if (carry)
        ans= (char)(carry+'0') +ans;
    
    cout<<ans<<'\n';

}