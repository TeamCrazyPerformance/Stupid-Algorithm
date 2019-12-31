#include <bits/stdc++.h> 
using namespace std; 

int answer =0;
int subsets(vector<int>& A, vector<vector<int>>& save, 
                 vector<int>& currentSet, int k) 
{ 
    save.push_back(currentSet); 
    for (int i = k; i < A.size(); i++) { 
        currentSet.push_back(A[i]); // 원소 포함 
        subsets(A, save, currentSet, i+1); 
        currentSet.pop_back(); // 원소 제외
    } 
  
    return 0; 
} 

int main(){
    int inputs,sum;
    cin>>inputs>>sum;
    vector<int>input;
    int holder;
    int checksum;
    checksum =sum;
    for(int i=0;i<inputs;i++){
        cin>>holder;
        input.push_back(holder);
    }
    vector<vector<int>> save;
    vector<int> subset;
    subsets(input,save,subset,0);
    for (int i = 1; i < save.size(); i++) {
        checksum=0;
        for (int j = 0; j < save[i].size(); j++){
            checksum+=save[i][j];
        }
        if (checksum==sum)answer++;
    }
    cout<<answer;
}
