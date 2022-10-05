//1753_최단경로 :: 2022_09_24__15:57
//https://www.acmicpc.net/problem/1753
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX_VALUE 999999


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int V = 0, E = 0, K = 0;
    int from = 0, to = 0, cost = 0;
    int dist[20001] = {0,};
    bool visit[20001] = {false, };
    vector<pair<int,int>> arr[20001];
    priority_queue<pair<int,int>> pq;

    cin>>V>>E>>K;
    for(int i = 0; i < E; i++){
        cin>>from>>to>>cost;
        arr[from].push_back(make_pair(cost,to));
    }
    for(int i = 1; i <= V; i++) { dist[i] = MAX_VALUE; }
    dist[K] = 0;
    pq.push(make_pair(0, K));
    while(!pq.empty()){
        int cn = pq.top().second;
        int cn_cost = -pq.top().first;
        pq.pop();
        if(visit[cn] == true) { continue; }
        visit[cn] = true;
        for(int i = 0; i < arr[cn].size(); i++){
            int cn_next = arr[cn][i].second;
            int cn_next_cost = arr[cn][i].first;
            if(visit[cn_next] == true) { continue; }
            if(dist[cn_next] > cn_cost + cn_next_cost) {
                dist[cn_next] = cn_cost + cn_next_cost;
                pq.push(make_pair(-dist[cn_next],cn_next));
            }
        }
    }
    for(int i = 1; i <= V; i++){
        if(dist[i] == MAX_VALUE) { cout<<"INF\n"; }
        else { cout<<dist[i]<<"\n"; }
    }

    return 0;    
}