//1865_웜홀 :: 2022_05_05__01:57
//https://www.acmicpc.net/problem/1865

#include<iostream>
#include<vector>
using namespace std;

#define MAX 10001

void print(int arr[][501], int N){
    cout<<"\n----------| START |----------\n";
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) { 
            if(arr[i][j] >= MAX) { cout<<"INF "; }
            else { cout<<arr[i][j]<<" "; }
        }
        cout<<"\n";
    }
    cout<<"----------| END |----------\n";
}

bool FW(int arr[][501], int N){
    for(int pass = 1; pass <= N; pass++){
        for(int from = 1; from <= N; from++){
            if(pass == from) { continue; }
            for(int to = from; to <= N; to++){
                if(arr[from][to] > arr[from][pass]+arr[pass][to]) { 
                    arr[from][to] = arr[from][pass] + arr[pass][to]; 
                    if(from == to || arr[from][to] < 0) { return true; }
                }
            }
        }
    }
    return false;
}

void fill_arr_MAX(int arr[][501], int N){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) { 
            if(i == j) { arr[i][j] = 0; }
            else { arr[i][j] = MAX; }
        }
    }
}

bool check_possiblity(int arr[][501], int N){
    for(int i = 1; i <= N; i++){
        if(arr[i][i] < 0) { return true; }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 0;
    int N = 0, M = 0, W = 0;
    int from = 0, to = 0, cost = 0;
    int arr[501][501] = { 0, }; 
    
    cin>>T;
    for(int k = 0; k < T; k++){
    // while(1){
        cin>>N>>M>>W;
        fill_arr_MAX(arr, N);
        for(int i = 0; i < M; i++){//도로
            cin>>from>>to>>cost;
            arr[from][to] = cost;
            arr[to][from] = cost;
        }
        for(int i = 0; i < W; i++){//웜홀
            cin>>from>>to>>cost;
            arr[from][to] = -cost;
        }
        //check
        // print(arr, N);

        if(FW(arr, N) == true) { cout<<"YES\n"; }
        else { cout<<"NO\n"; }

        //check
        // print(arr, N);

        // if(check_possiblity(arr, N) == true) { cout<<"YES\n"; }
        // else { cout<<"NO\n"; }
    }
    return 0;
}
