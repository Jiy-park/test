//1967_트리의 지름 :: 2022_09_23__00:42
//https://www.acmicpc.net/problem/1967
#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int>> tree[10001];
bool visit[10001];
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

// void print(int N) {
//     cout<<"\nprint\n";
//     for(int i = 0; i < N; i++){
//         for(int j = 0; j < tree[N].size(); j++) { cout<<tree[i][j].first<<" "<<tree[i][j].second<<"\n"; }
//     }
// }

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0;
    int max = 0, max_node = 0;
    cin>>N;

    for(int i = 0; i < N-1; i++){
        int from = 0, to = 0, cost = 0;
        cin>>from>>to>>cost;
        tree[from].push_back(make_pair(to, cost));
        tree[to].push_back(make_pair(from, cost));
    }

    // print(N);


    DFS(1, max, max_node, 0);
    DFS(max_node, max, max_node, 0);
    cout<<max;
    return 0;    
}