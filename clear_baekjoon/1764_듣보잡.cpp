//1764_듣보잡 :: 2022_03_18__17:38
//https://www.acmicpc.net/problem/1764

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, M = 0;
    string name;
    vector<string> v;
    vector<int> index;

    cin>>N>>M;

    for(int i = 0; i < N+M; i++){
        cin>>name;
        v.push_back(name);
    }

    sort(v.begin(), v.end());
    
    for(unsigned int i = 0; i < v.size()-1; i++){
        if(v[i] == v[i+1]){ 
            index.push_back(i); 
            i++;    
        }
    }
    
    cout<<index.size()<<"\n";
    for(unsigned int i = 0; i < index.size(); i++) { cout<<v[index[i]]<<"\n"; }

    return 0;
}


