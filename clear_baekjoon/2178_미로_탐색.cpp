//2178_미로 탐색 :: 2022_03_20__16:34
//https://www.acmicpc.net/problem/2178

#include<iostream>
#include<queue>
using namespace std;

void print_arr(int arr[][100], int N, int M){
    cout<<"\n-----------| start |-----------\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) { cout<<arr[i][j]; }
        cout<<"\n";
    }
    cout<<"\n-----------| end |-----------\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, M = 0;
    int yp[4] = {0, 1, 0, -1};
    int xp[4] = {1, 0, -1, 0};
    int arr[100][100] = { 0, };
    char ch;
    queue<pair<int,int>> Q;

    cin>>N>>M;
    
    //init_arr
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){ 
            cin>>ch; 
            if(ch == '1') { arr[i][j] = 1; }
        }
    }

    // //print_arr
    // print_arr(arr, N, M);
    
    Q.push(make_pair(0,0));
    while(!Q.empty()){
        int Y = Q.front().first, X = Q.front().second;
        for(int i = 0; i < 4; i++){
            if(Y+yp[i] < 0 || Y+yp[i] >= N || X+xp[i] < 0 || X+xp[i] >= M) { continue; }
            else{
                if(arr[Y+yp[i]][X+xp[i]] == 1){
                    arr[Y+yp[i]][X+xp[i]] = arr[Y][X]+1;
                    Q.push(make_pair(Y+yp[i], X+xp[i]));
                }
                else if(arr[Y+yp[i]][X+xp[i]] > 1){
                    if(arr[Y+yp[i]][X+xp[i]] > arr[Y][X]+1) { arr[Y+yp[i]][X+xp[i]] = arr[Y][X]+1; }
                }
            }
        }   
        Q.pop();
    }

    // //print_arr
    // print_arr(arr, N, M);

    cout<<arr[N-1][M-1];
    return 0;
}