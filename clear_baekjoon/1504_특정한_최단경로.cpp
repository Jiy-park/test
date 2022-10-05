//1504_특정한 최단경로 :: 2022_09_25__21:38
//https://www.acmicpc.net/problem/1504
#include<iostream>
#include<vector>
#include<queue>
#define MAX_VALUE 99999999
using namespace std;

void Dijkstra(vector<pair<int,int>> arr[801], bool visit[][801], int dist[][801], int start, int v){
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int cn = pq.top().second;
        int cn_cost = -pq.top().first;
        pq.pop();
        if(visit[v][cn] == true) { continue; }
        visit[v][cn] = true;
        for(int i = 0; i < arr[cn].size(); i++){
            int cn_next = arr[cn][i].second;
            int cn_next_cost = arr[cn][i].first;
            if(visit[v][cn_next] == true) { continue; }
            if(dist[v][cn_next] > cn_cost + cn_next_cost){
                dist[v][cn_next] = cn_cost + cn_next_cost;
                pq.push(make_pair(-dist[v][cn_next], cn_next));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, E = 0;
    int v1 = 0, v2 = 0;
    int from = 0, to = 0, cost = 0;
    vector<pair<int,int>> arr[801];
    bool visit[3][801] = {false, };
    int dist[3][801];

    cin>>N>>E;
    for(int i = 0; i < E; i++){
        cin>>from>>to>>cost;
        arr[from].push_back(make_pair(cost,to));
        arr[to].push_back(make_pair(cost,from));
    }
    
    cin>>v1>>v2;

    for(int i = 1; i <= N; i++) { 
        dist[0][i] = MAX_VALUE; 
        dist[1][i] = MAX_VALUE;
        dist[2][i] = MAX_VALUE;
    }

    dist[0][1] = 0;     dist[1][v1] = 0;     dist[2][v2] = 0;
    Dijkstra(arr, visit, dist, 1, 0);
    Dijkstra(arr, visit, dist, v1, 1);
    Dijkstra(arr, visit, dist, v2, 2);
    
    long long int v1_v2_N = dist[0][v1] + dist[1][v2] + dist[2][N];
    long long int v2_v1_N = dist[0][v2] + dist[2][v1] + dist[1][N];
    long long int answer = v1_v2_N < v2_v1_N ? v1_v2_N : v2_v1_N;
    if(answer >= MAX_VALUE) { answer = -1; }
    cout<<answer;
     
    return 0;    
}

