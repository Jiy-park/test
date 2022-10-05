//1958_LCS3 :: 2022_09_14__22:23
//https://www.acmicpc.net/problem/1958

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct pos{
    int y = 0;
    int x = 0;
};

void print_arr(int arr[][301], int N, int M){
    cout<<"\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) { cout<<arr[i][j]<<" "; }
        cout<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int arr[301][301] = {0,};
    int N = 0, M = 0, year = 0;
    int yp[4] = {0, 1, 0, -1};
    int xp[4] = {1, 0, -1, 0};
    bool visited[301][301] = {false,};
    stack<pos> s;
    queue<pos> q;
    queue<pair<pos, int>> melt;

    cin>>N>>M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>arr[i][j];
            if(arr[i][j] != 0) { q.push({i, j}); }
        }
    }

    while(!q.empty()){
        int cycle = q.size();
        for( ; cycle > 0; cycle--){
            int qy = q.front().y;
            int qx = q.front().x;
            if(visited[qy][qx] == false){
                s.push({qy, qx});
                while(!s.empty()){
                    int sy = s.top().y;
                    int sx = s.top().x;
                    int count = 0;
                    visited[sy][sx] = true;
                    for(int i = 0; i < 4; i++){
                        if(arr[sy+yp[i]][sx+xp[i]] == 0) { count++; }
                        else { s.push({sy+yp[i], sx+xp[i]}); }
                    }
                    melt.push({{sy,sx}, arr[sy][sx]-count<0 ? 0:arr[sy][sx]-count});
                    s.pop();
                }
            }
        }
        year++;
    }
    return 0;
}