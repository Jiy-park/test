//2206_벽 부수고 이동하기 :: 2022_09_19__22:05
//https://www.acmicpc.net/problem/2206
#include<iostream>
#include<queue>
using namespace std;

char arr1[1001][1001];
int arr2[2][1001][1001];
bool visit[2][1001][1001];
struct pos{
    int y = 0;
    int x = 0;
    int crash = 0;
    int num = 0;
};



void print(int N, int M){
    cout<<"\n\n";
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++) { cout<<arr2[i][j][k]<<""; }
            cout<<"\n";
        }
        cout<<"\n\n\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, M = 0;
    int yp[4] = {0, 1, 0, -1};
    int xp[4] = {1, 0, -1, 0};
    int num = 1;
    queue<pos> q;
    
    cin>>N>>M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) { cin>>arr1[i][j]; }
    }
    q.push({0, 0, 0, 1});
    visit[0][0][0] = true;
    visit[1][0][0] = true;
    arr2[0][0][0] = num;
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int crash = q.front().crash;
        num = q.front().num;
        for(int i = 0; i < 4; i++){
            if(y+yp[i] >= 0 && y+yp[i] < N && x+xp[i] >= 0 && x+xp[i] < M){
                if(visit[crash][y+yp[i]][x+xp[i]] == false){
                    if(arr1[y+yp[i]][x+xp[i]] == '1') { 
                        if(crash == 0 && visit[0][y+yp[i]][x+xp[i]] == false) { 
                            q.push({y+yp[i], x+xp[i], 1, num+1}); 
                            arr2[1][y+yp[i]][x+xp[i]] = num + 1;
                        }
                    }
                    else { 
                        q.push({y+yp[i], x+xp[i], crash, num+1}); 
                        arr2[crash][y+yp[i]][x+xp[i]] = num + 1;
                    }
                    visit[crash][y+yp[i]][x+xp[i]] = true;
                }
            }
        }
        q.pop();
    }

    
    // print(N,M);

    if(arr2[0][N-1][M-1] != 0 && arr2[1][N-1][M-1] != 0) { 
        if(arr2[0][N-1][M-1] < arr2[1][N-1][M-1]) { cout<<arr2[0][N-1][M-1]; } 
        else { cout<<arr2[1][N-1][M-1]; }
    }
    else if (arr2[0][N-1][M-1] != 0) { cout<<arr2[0][N-1][M-1]; } 
    else if (arr2[1][N-1][M-1] != 0) { cout<<arr2[1][N-1][M-1]; }       
    else { cout<<-1; }
    return 0;    
}