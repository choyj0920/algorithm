// baek 11723 집합
#include <iostream>
#include <string>
using namespace std;

int M,num,S;
string input;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>M;
    while(M--){
        input.clear();
        cin >> input;
        if (input=="add"){
            cin>>num;
            S |= (1<<num);
        }else if(input=="remove"){
            cin>>num;
            S &= ~(1<<num);
        }else if(input=="check"){
            cin>>num;
            if (S &(1<<num)) cout<<"1\n";
            else cout<<"0\n";
        }else if(input =="toggle"){
            cin>>num;
            S ^= (1<<num);
        }else if (input =="all"){
            S |= (1<<21)-1;
        }else if (input == "empty"){
            S =0;
        }

        
    }
 
}