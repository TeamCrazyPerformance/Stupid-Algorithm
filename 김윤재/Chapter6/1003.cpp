#include <bits/stdc++.h>
using namespace std;

//스타벅스에서 이상한 냄새 난다
int main() {
    int n;
    int arr[10000];//inputs
    int maxit=0,maxval=0;
    //0,1
    int fib[10000][2];
    fib[0][0]=1;
    fib[0][1]=0;
    fib[1][0]=0;
    fib[1][1]=1;
    
    cin>>n;
    for (int i = 0; i < n; i++)cin>>arr[i];
    for (int i = 0; i < n; i++){
        if(arr[i]>maxval){maxit=i;}
    }
    for(int i = 2; i<=arr[maxit];i++){
        fib[i][0]=fib[i-1][0]+fib[i-2][0];
        fib[i][1]=fib[i-1][1]+fib[i-2][1];
    }
    for (int i = 0; i < n; i++){
            cout<<fib[arr[i]][0]<<" "<<fib[arr[i]][1]<<"\n";
    }
    return 0;
}

