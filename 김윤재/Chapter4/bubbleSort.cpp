#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,in;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>in;
        arr.push_back(in);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j1])
            swap(arr[j],arr[j+1]);
        }
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i];
    }
}