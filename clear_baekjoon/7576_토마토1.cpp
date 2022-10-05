//7576_토마토1 :: 2022_03_14__15:08
//https://www.acmicpc.net/problem/7576

#include<iostream>
#include<queue>
using namespace std;

void print_arr(int** arr, int M, int N){
    cout<<"\n-----------------------\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) { cout<<arr[i][j]<<" "; }
        cout<<"\n";
    }
    cout<<"-----------------------\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int M = 0, N = 0;
    int day = 0;
    int unripe_tomato = 0;
    queue<pair<int, int>> Q;
    int XP[4] = {1, 0, -1, 0};
    int YP[4] = {0, 1, 0, -1};
    int** arr;

    cin>>M>>N;

    //create_arr
    arr = new int*[N];
    for(int i = 0; i < N; i++) { arr[i] = new int[M]; }

    //input_data
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>arr[i][j]; 
            if(arr[i][j] == 0) { unripe_tomato++; }
            if(arr[i][j] == 1) { Q.push(make_pair(i, j)); }
        }
    }

    //print_arr
    // print_arr(arr,M,N);

    while(!Q.empty()){
        for(int i = 0; i < 4; i++){
            if(Q.front().first+YP[i] < 0 || Q.front().first+YP[i] >= N ||
                Q.front().second+XP[i] < 0 || Q.front().second+XP[i] >= M){
                continue;
            }
            else{
                if(arr[Q.front().first+YP[i]][Q.front().second+XP[i]] == 0){
                    arr[Q.front().first+YP[i]][Q.front().second+XP[i]] = arr[Q.front().first][Q.front().second]+1;
                    if(arr[Q.front().first][Q.front().second] > day) { day++; }
                    Q.push(make_pair(Q.front().first+YP[i], Q.front().second+XP[i]));
                    unripe_tomato--;
                }
            }
        }
        Q.pop();
    }
    if(unripe_tomato == 0) { cout<<day; }
    else { cout<<-1; }

    //delete_arr
    for(int i = 0; i < N; i++) { delete[] arr[i]; }
    delete[] arr;
    return 0;
}