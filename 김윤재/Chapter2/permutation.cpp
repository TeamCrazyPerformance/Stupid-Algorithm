#include <bits/stdc++.h>
using namespace std;

vector<bool> chosen;
vector<int> permutationSet;

int permutations(int input, vector<vector<int>>& save) 
{
    if (permutationSet.size()==input){
        save.push_back(permutationSet);
    }
    for (int i = 1; i <= input; i++) {
        if(chosen[i])continue;
        chosen[i]=true;
        permutationSet.push_back(i);
        permutations(input,save);
        chosen[i]=false;
        permutationSet.pop_back();
    }    
    return 0; 
}

int main(){
    int input = 4;
    
    vector<vector<int>> save;

    permutations(input,save);

    for (int i = 0; i < save.size(); i++) { 
        for (int j = 0; j < save[i].size(); j++) 
            cout << save[i][j] << " "; 
        cout << endl; 
    } 
}