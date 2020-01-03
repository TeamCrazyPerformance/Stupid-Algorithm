#include <bits/stdc++.h> 
using namespace std; 
int main(){
    int n,o;
    int maxSum =0;
    vector<int> arr;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>o;
        arr.push_back(o);
    }
    for (int i =0;i<n;i++){
        int curSum=0;
        for(int j=i;j<n;j++){
            curSum+=arr[j];
            maxSum=max(maxSum,curSum);
        }
    }
    cout<<maxSum;
}