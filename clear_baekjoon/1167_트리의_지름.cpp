//1167_트리의 지름 :: 2022_09_23__00:24
//https://www.acmicpc.net/problem/1167
#include<iostream>
#include<vector>
#include<stack>

using namespace std;


vector<pair<int,int>> tree[100001];    
bool visit[100001];

void print(int N){
    for(int i = 1; i <= N; i++){
        cout<<i<<"\n";
        for(int j = 0; j < tree[i].size(); j++) { cout<<tree[i][j].first<<" "<<tree[i][j].second<<"\n";  }    
    }    
}

void DFS(int n, int& max, int& max_node, int sum){
    visit[n] = true;
    if(sum > max) { 
        max = sum; 
        max_node = n;
    }
    for(int i = 0; i < tree[n].size(); i++){
        if(visit[tree[n][i].first] == false) { DFS(tree[n][i].first, max, max_node, sum + tree[n][i].second); }
    }
    visit[n] = false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0;
    int max = 0;
    int max_node = 0;
    cin>>N;
    for(int i = 1; i <= N; i++){
        int from = 0, to = 0, cost = 0;
        cin>>from;
        while(1){
            cin>>to;
            if(to == -1) { break; }
            cin>>cost;
            tree[from].push_back(make_pair(to,cost));
        }       
    }
    DFS(1, max, max_node, 0);
    DFS(max_node, max, max_node, 0);
    cout<<max;
    //print(N);
  
    return 0;    
}