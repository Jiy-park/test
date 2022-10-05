//11399_ATM :: 2022_03_18__17:07
//https://www.acmicpc.net/problem/11399

#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue<int, vector<int>, greater<int>> PQ;
    int N = 0;
    int P = 0;
    int need_time = 0;
    int total_need_time = 0;

    cin>>N;

    for(int i = 0; i < N; i++){
        cin>>P;
        PQ.push(P);
    }

    while(!PQ.empty()){
        need_time += PQ.top();
        total_need_time += need_time;
        PQ.pop();
    }

    cout<<total_need_time;

    return 0;
}


