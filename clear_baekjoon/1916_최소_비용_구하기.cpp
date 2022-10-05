//1916_최소 비용 구하기 :: 2022_09_24__02:01
//https://www.acmicpc.net/problem/1916
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int N = 0, M = 0, from = 0, to = 0, cost = 0;
    int dist[1001];
    bool visit[1001] = {false,};
    vector<pair<int,int>> arr[1001];
    priority_queue<pair<int,int>> pq;

    cin>>N>>M;
    for(int i = 0; i < M; i++){
        cin>>from>>to>>cost;
        arr[from].push_back({cost,to});
    }
    cin>>from>>to;
    for(int i = 1; i <= N; i++) { dist[i] = INT32_MAX; }

    dist[from] = 0;
    pq.push(make_pair(0, from));
    while(!pq.empty()){
        int cn_cost = -pq.top().first;
        int cn = pq.top().second;
        pq.pop();
        if(visit[cn] == true) { continue; }
        visit[cn] = true;
        for(int i = 0; i < arr[cn].size(); i++){
            int cn_next = arr[cn][i].second;
            int cn_next_cost = arr[cn][i].first;
            if(visit[cn_next] == true) { continue; }
            if(dist[cn_next] > cn_next_cost + cn_cost) {
                dist[cn_next] = cn_next_cost + cn_cost;
                pq.push(make_pair(-dist[cn_next], cn_next));
            }
        }
    }
    cout<<dist[to];
    return 0;    
}