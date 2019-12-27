#include <iostream> 
#include <vector> 

using namespace std; 
  

int search(vector<int> input,vector<vector<int>> &subsets,int n,int k) 
{
    if(k ==n+1){
        
    } else{
        subset.push_back(k);
        search(k+1);
        subset.pop_back();
        search(k+1);
    }
    
}

int main(){
    vector<int> input {1,2,3,4,5};
    vector<vector<int>> subsets;
    search(input,&subsets,input.size(),1);
    for (auto i = subsets.begin(); i != subsets.end(); ++i){
    for (auto j = j.begin(); j != path.end(); ++j)
    cout << *j << ' ';}
}