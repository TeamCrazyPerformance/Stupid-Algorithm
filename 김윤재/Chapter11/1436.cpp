#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,cnt=0;
    cin>>n;
    for(int i=665;;i++){
        for(int j=i;j>0;j/=10){
            if(j%1000==666){cnt++;break;}
        }
        if(cnt==n){
                cout<<i<<endl;
                break;
            }
    }
    return 0;
}
