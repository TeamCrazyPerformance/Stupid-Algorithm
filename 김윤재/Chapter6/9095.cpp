#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    vector<int> ns;
    int arr[12]={0};
    arr[0]=0;arr[1]=1;arr[2]=2;arr[3]=4;
    cin>>t;
    for(int i=0;i<t;i++){cin>>n;ns.push_back(n);}
    
    for(int i=4;i<=*max_element(ns.begin(),ns.end());i++){
            arr[i]+=arr[i-3];
            arr[i]+=arr[i-2];
            arr[i]+=arr[i-1];
            //cout<<"maxel i="<<i<<"   "<<arr[i]<<endl;
    }
    for(int i=0;i<t;i++)
    cout//<<ns[i]<<"  "
    <<arr[ns[i]]<<"\n";
    return 0;
}

//경우의 수 때려박으면서 팩토리얼로 풀수는 없을까?

