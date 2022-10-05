//7569_토마토2 :: 2022_03_14__16:01
//https://www.acmicpc.net/problem/7569

#include<iostream>
#include<queue>
using namespace std;

struct pair_{
    int first;
    int second;
    int third;
};


void print_arr(int*** arr, int M, int N, int H){
    cout<<"\n-----------------------\n";
    for(int k = 0; k < H; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++) { cout<<arr[k][i][j]<<" "; }
            cout<<"\n";
        }
    }
    cout<<"-----------------------\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int M = 0, N = 0, H = 0;
    int day = 0;
    int unripe_tomato = 0;
    queue<pair_> Q;
    int XP[6] = {1, 0, -1, 0, 0, 0};
    int YP[6] = {0, 1, 0, -1, 0, 0};
    int ZP[6] = {0, 0, 0, 0, 1, -1};
    int*** arr;

    cin>>M>>N>>H;

    //create_arr
    arr = new int**[H];
    for(int i = 0; i < H; i++){
        arr[i] = new int*[N];
        for(int j = 0; j < N; j++) { arr[i][j] = new int[M]; }
    }

    //input_data
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                cin>>arr[i][j][k]; 
                if(arr[i][j][k] == 0) { unripe_tomato++; }
                if(arr[i][j][k] == 1) { Q.push({i, j, k}); }
            }
        }
    }

    // // print_arr
    // print_arr(arr, M, N, H);

    while(!Q.empty()){
        for(int i = 0; i < 6; i++){
            if(Q.front().first+ZP[i] < 0 || Q.front().first+ZP[i] >= H ||
                Q.front().second+YP[i] < 0 || Q.front().second+YP[i] >= N ||
                Q.front().third+XP[i] < 0 || Q.front().third+XP[i] >= M ){
                continue;
            }
            else{
                if(arr[Q.front().first+ZP[i]][Q.front().second+YP[i]][Q.front().third+XP[i]] == 0){
                    arr[Q.front().first+ZP[i]][Q.front().second+YP[i]][Q.front().third+XP[i]] = arr[Q.front().first][Q.front().second][Q.front().third]+1;
                    if(arr[Q.front().first][Q.front().second][Q.front().third] > day) { day++; }
                    Q.push({Q.front().first+ZP[i], Q.front().second+YP[i], Q.front().third+XP[i]});
                    unripe_tomato--;
                }
            }
        }
        Q.pop();
    }
    if(unripe_tomato == 0) { cout<<day; }
    else { cout<<-1; }


    /////////////////////////////////아래부분 잘못 됨 고쳐야함
    //delete_arr
    // for(int i = 0; i < H; i++){
    //     for(int j = 0; i < N; j++) { delete[] arr[i][j]; }
    // }
    // for(int i = 0; i < H; i++) { delete[] arr[i]; }
    // delete[] arr;
    return 0;
}