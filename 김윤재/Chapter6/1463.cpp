#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[1000001]={0};//1~10^6
    //arr[1]=0;
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+1;
        if(i%3==0)
            arr[i]=min(arr[i],arr[i/3]+1);
        if(i%2==0)
            arr[i]=min(arr[i],arr[i/2]+1);
        //cout<<"i:"<<i<<" arr[i]:"<<arr[i]<<endl;
    }

    cout<<arr[n];
    return 0;
}
