//1697_숨바꼭질 :: 2022_04_02__01:30
//https://www.acmicpc.net/problem/1697

#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, K = 0;
    bool visited[100001] = { 0, };
    queue<pair<int,int>> Q;

    cin>>N>>K;
    Q.push(make_pair(N,0));
    visited[N] = true;
    while(Q.front().first != K){
        int curr = Q.front().first;
        int curr_sec = Q.front().second;
        if(curr-1 >= 0) {
            if(visited[curr-1] == false) { Q.push(make_pair(curr-1,curr_sec+1)); visited[curr-1] = true;}
        }
        if(curr+1 <= 100001){
            if(visited[curr+1] == false) { Q.push(make_pair(curr+1,curr_sec+1)); visited[curr+1] = true;}
        }
        if(curr*2 <= 100001){
            if(visited[curr*2] == false) { Q.push(make_pair(curr*2,curr_sec+1)); visited[curr*2] = true;}
        }
        Q.pop();
    }

    cout<<Q.front().second;
    return 0;
}
