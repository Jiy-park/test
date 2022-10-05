//11779_최소비용 구하기2 :: 2022_09_26__00:39
//https://www.acmicpc.net/problem/11779
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
stack<int> make_root_stack(int root[], int from, int to){
    stack<int> answer;  
    answer.push(to);
    while(true){
        answer.push(root[to]);
        to = root[to];
        if(to == from) { break; }
    }
    return answer;
}
void Dijkstra(vector<pair<int,int>> arr[], int dist[], bool visit[], int root[], int start){
    stack<int> asnwer;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));
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
            if(dist[cn_next] > cn_next_cost + cn_cost) {
                dist[cn_next] = cn_next_cost + cn_cost;
                pq.push(make_pair(-dist[cn_next], cn_next));
                root[cn_next] = cn;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, M = 0;
    int from = 0, to = 0, cost = 0;
    int dist[1001] = {0, };
    bool visit[1001] = {0, };
    int root[1001] = {0, };
    vector<pair<int,int>> arr[1001];
    stack<int> answer;

    cin>>N>>M;
    for(int i = 0; i < M; i++){
        cin>>from>>to>>cost;
        arr[from].push_back(make_pair(cost, to));
    }
    cin>>from>>to;
    for(int i = 1; i <= N; i++) { dist[i] = INT32_MAX; }
    Dijkstra(arr, dist, visit, root, from);
    answer = make_root_stack(root, from, to);
    cout<<dist[to]<<"\n"<<answer.size()<<"\n";
    while(!answer.empty()) {  
        cout<<answer.top()<<" ";
        answer.pop();
    }
    return 0;    
}

